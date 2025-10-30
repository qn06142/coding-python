#!/usr/bin/env python3
"""
evolutionary_polygon_search_with_output.py

Self-contained evolutionary search for an integer simple polygon with n vertices
and exactly k interior diagonals.

This variant writes found/ best solutions to an output file instead of only printing.

Usage:
    python evolutionary_polygon_search_with_output.py --demo single --output solutions.txt
    python evolutionary_polygon_search_with_output.py --demo batch --output batch_results.txt
"""

import random
import math
import time
import itertools
import argparse
import os

# Optional: process_map for nice progress bar in parallel runs.
try:
    from tqdm.contrib.concurrent import process_map
except Exception:
    process_map = None

# ---------------- Geometry helpers (integer exact where possible) ----------------
def orient(a, b, c):
    return (b[0]-a[0])*(c[1]-a[1]) - (b[1]-a[1])*(c[0]-a[0])

def on_segment(a, b, p):
    if orient(a,b,p) != 0:
        return False
    return min(a[0],b[0]) <= p[0] <= max(a[0],b[0]) and min(a[1],b[1]) <= p[1] <= max(a[1],b[1])

def segments_intersect(a,b,c,d):
    # closed-segment intersection including endpoints
    o1 = orient(a,b,c)
    o2 = orient(a,b,d)
    o3 = orient(c,d,a)
    o4 = orient(c,d,b)
    if o1==0 and on_segment(a,b,c): return True
    if o2==0 and on_segment(a,b,d): return True
    if o3==0 and on_segment(c,d,a): return True
    if o4==0 and on_segment(c,d,b): return True
    return (o1>0) != (o2>0) and (o3>0) != (o4>0)

def bbox(a,b):
    return (min(a[0],b[0]), min(a[1],b[1]), max(a[0],b[0]), max(a[1],b[1]))

def bbox_intersect(bb1, bb2):
    x1min,y1min,x1max,y1max = bb1
    x2min,y2min,x2max,y2max = bb2
    return not (x1max < x2min or x2max < x1min or y1max < y2min or y2max < y1min)

def midpoint(a,b):
    return ((a[0]+b[0])/2.0, (a[1]+b[1])/2.0)

def point_in_polygon(pt, poly):
    # ray-casting: float arithmetic is OK for midpoint test
    x,y = pt
    inside = False
    n = len(poly)
    for i in range(n):
        x1,y1 = poly[i]
        x2,y2 = poly[(i+1)%n]
        if ((y1 > y) != (y2 > y)):
            t = (x2 - x1) * (y - y1) / (y2 - y1) + x1
            if t > x:
                inside = not inside
    return inside

# ---------------- Polygon validation and counting ----------------
def is_simple_polygon(poly):
    n = len(poly)
    if n < 3:
        return False
    if len(set(poly)) != n:
        return False
    # no three consecutive collinear
    for i in range(n):
        if orient(poly[i-1], poly[i], poly[(i+1)%n]) == 0:
            return False
    # edges check with bbox early-out
    edges = []
    for i in range(n):
        a = poly[i]; b = poly[(i+1)%n]
        edges.append((a,b,i,(i+1)%n,bbox(a,b)))
    for i, (a,b,ai,bi,bba) in enumerate(edges):
        for j in range(i+1, len(edges)):
            c,d,cj,dj,bbb = edges[j]
            # skip if share vertex
            if ai==cj or ai==dj or bi==cj or bi==dj:
                continue
            if not bbox_intersect(bba, bbb):
                continue
            if segments_intersect(a,b,c,d):
                return False
    return True

def segment_strictly_inside_polygon(a,b, poly):
    # midpoint inside
    mid = midpoint(a,b)
    if not point_in_polygon(mid, poly):
        return False
    # no intersections with polygon edges except at endpoints
    n = len(poly)
    for i in range(n):
        p = poly[i]
        q = poly[(i+1)%n]
        if p==a or p==b or q==a or q==b:
            continue
        if segments_intersect(a,b,p,q):
            return False
    # no other vertex on open segment
    for v in poly:
        if v==a or v==b: continue
        if on_segment(a,b,v):
            return False
    return True

def count_interior_diagonals(poly):
    n = len(poly)
    cnt = 0
    for i in range(n):
        for j in range(i+1, n):
            if j == i+1: continue
            if i==0 and j==n-1: continue
            if segment_strictly_inside_polygon(poly[i], poly[j], poly):
                cnt += 1
    return cnt

# ---------------- Faster 2-opt crossing remover ----------------
def remove_crossings_2opt(poly, max_passes=6):
    n = len(poly)
    if n < 4:
        return poly
    for pass_no in range(max_passes):
        any_swap = False
        # build edges and bboxes
        edges = []
        for i in range(n):
            a = poly[i]; b = poly[(i+1)%n]
            edges.append((a,b,i,(i+1)%n,bbox(a,b)))
        for i, (a,b,ai,bi,bba) in enumerate(edges):
            j = i+2
            while j < n:
                c,d,cj,dj,bbb = edges[j]
                # skip adjacent / shared endpoints
                if ai==cj or ai==dj or bi==cj or bi==dj:
                    j += 1
                    continue
                if not bbox_intersect(bba, bbb):
                    j += 1
                    continue
                if segments_intersect(a,b,c,d):
                    # reverse the shorter arc between i+1 .. j
                    left_len = j - i
                    right_len = n - left_len
                    if left_len <= right_len:
                        new_poly = poly[:i+1] + list(reversed(poly[i+1:j+1])) + poly[j+1:]
                    else:
                        # reverse complementary arc (j+1 .. i) by rotating
                        seg = poly[j+1:] + poly[:i+1]
                        seg.reverse()
                        new_poly = seg[len(poly)-(i+1):] + poly[i+1:j+1] + seg[:len(poly)-(i+1)]
                    poly = new_poly
                    any_swap = True
                    break
                j += 1
            if any_swap:
                break
        if not any_swap:
            break
    # jitter any collinear triples and fix duplicates lightly
    for t in range(n):
        if orient(poly[t-1], poly[t], poly[(t+1)%n]) == 0:
            x,y = poly[t]
            gx = random.choice([-1,0,1])
            gy = random.choice([-1,0,1])
            if gx==0 and gy==0:
                gx = 1
            poly[t] = (x+gx, y+gy)
    seen = set()
    for idx in range(n):
        tries = 0
        while poly[idx] in seen and tries < 8:
            x,y = poly[idx]
            poly[idx] = (x + random.choice([-1,1]), y + random.choice([-1,1]))
            tries += 1
        seen.add(poly[idx])
    return poly

# ---------------- Initialization: convex base + light perturbations ----------------
def make_convex_polygon(n, radius=100, cx=0, cy=0, jitter=0):
    pts = []
    for i in range(n):
        ang = 2*math.pi * i / n
        r = radius + (random.randint(-jitter, jitter) if jitter>0 else 0)
        x = int(round(cx + r*math.cos(ang)))
        y = int(round(cy + r*math.sin(ang)))
        pts.append((x,y))
    k = random.randrange(n)
    return pts[k:]+pts[:k]

def init_population(n, pop_size, coord_box=200, jitter=1):
    pop = []
    base = make_convex_polygon(n, radius=coord_box//2, jitter=jitter)
    pop.append(base[:])
    for _ in range(pop_size-1):
        if random.random() < 0.7:
            # small coordinate jitter
            ind = [(x + random.randint(-jitter,jitter), y + random.randint(-jitter,jitter)) for (x,y) in base]
            ind = remove_crossings_2opt(ind, max_passes=3)
        else:
            # small shuffle on a slice (cheap)
            ind = base[:]
            i = random.randrange(n)
            j = random.randrange(n)
            if i>j: i,j = j,i
            slice_part = ind[i:j+1]
            random.shuffle(slice_part)
            ind[i:j+1] = slice_part
            ind = remove_crossings_2opt(ind, max_passes=4)
        if not is_simple_polygon(ind):
            ind = base[:]
        pop.append(ind)
    return pop

# ---------------- Genetic operators ----------------
def tournament_selection(pop, fitnesses, tsize=3):
    best = None
    best_fit = -10**9
    for _ in range(tsize):
        i = random.randrange(len(pop))
        if fitnesses[i] > best_fit:
            best_fit = fitnesses[i]
            best = pop[i]
    return best

def order_crossover(parent_a, parent_b):
    n = len(parent_a)
    # try OX assuming identical multisets of points (true for our population)
    try:
        a = parent_a
        b = parent_b
        i = random.randrange(n)
        j = random.randrange(n)
        if i>j: i,j = j,i
        child = [None]*n
        for k in range(i,j+1):
            child[k] = a[k]
        ptr = (j+1)%n
        for k in range(n):
            cand = b[(j+1+k)%n]
            if cand in child:
                continue
            child[ptr] = cand
            ptr = (ptr+1)%n
        return child
    except Exception:
        # fallback: splice + fix duplicates
        i = random.randrange(n)
        j = random.randrange(n)
        if i>j: i,j = j,i
        child = parent_a[:i] + parent_b[i:j] + parent_a[j:]
        pts = set(child)
        missing = [p for p in parent_a if p not in pts]
        res = []
        used = set()
        it = iter(missing)
        for p in child:
            if p not in used:
                res.append(p); used.add(p)
            else:
                res.append(next(it))
        return res

def swap_mutation(ind, swap_prob=0.2):
    new = ind[:]
    if random.random() < swap_prob:
        i = random.randrange(len(ind))
        j = random.randrange(len(ind))
        new[i], new[j] = new[j], new[i]
    return new

def coord_mutation(ind, mut_prob=0.3, delta=3):
    new = ind[:]
    if random.random() < mut_prob:
        i = random.randrange(len(ind))
        x,y = new[i]
        new[i] = (x + random.randint(-delta,delta), y + random.randint(-delta,delta))
    return new

# ---------------- I/O helper for solutions ----------------
def write_solution_to_file(path, n, k, found_exact, elapsed, generation, diag_count, poly):
    # Append a readable block describing the solution
    header = f"# Solution n={n} k={k} found_exact={found_exact} time={elapsed:.3f}s gen={generation} diags={diag_count}\n"
    with open(path, 'a') as f:
        f.write(header)
        for (x,y) in poly:
            f.write(f"{x} {y}\n")
        f.write("\n")

# ---------------- Evolutionary search main ----------------
def evolutionary_search(n, k, time_limit=10.0, pop_size=8000, seed=None, output_file=None):
    # per-worker reseeding for diversity
    if seed is not None:
        random.seed(seed)
    else:
        random.seed((os.getpid(), time.time()))

    start = time.time()
    pop = init_population(n, pop_size, coord_box=10 ** 9, jitter=1)
    best = None
    best_fit = -10**9
    generation = 0

    def fitness_value(poly):
        if not is_simple_polygon(poly):
            return -10**6, None
        d = count_interior_diagonals(poly)
        return -abs(k - d), d

    fitnesses = []
    diags = []
    for ind in pop:
        ind = remove_crossings_2opt(ind)
        fit, d = fitness_value(ind)
        fitnesses.append(fit)
        diags.append(d if d is not None else -1)
        if fit > best_fit:
            best_fit = fit
            best = (ind, diags[-1])

    # main loop
    while time.time() - start < time_limit:
        generation += 1
        newpop = []
        newfit = []
        newdiags = []
        # elitism
        ranked = sorted(range(len(pop)), key=lambda i: fitnesses[i], reverse=True)
        for idx in ranked[:2]:
            newpop.append(pop[idx])
            newfit.append(fitnesses[idx])
            newdiags.append(diags[idx])
        # create children
        while len(newpop) < pop_size:
            a = tournament_selection(pop, fitnesses, tsize=3)
            b = tournament_selection(pop, fitnesses, tsize=3)
            child = order_crossover(a, b)
            child = swap_mutation(child, swap_prob=0.4)
            # decay delta mutation amplitude over generations
            delta = max(1, int(5*(1 - min(generation/200.0, 0.99))))
            child = coord_mutation(child, mut_prob=0.5, delta=delta)
            child = remove_crossings_2opt(child)
            fit, d = fitness_value(child)
            newpop.append(child)
            newfit.append(fit)
            newdiags.append(d if d is not None else -1)
            if fit > best_fit:
                best_fit = fit
                best = (child, newdiags[-1])
                print(f"[gen {generation}] new best d={best[1]} (fit={best_fit})")
                if best[1] == k:
                    elapsed = time.time() - start
                    print(f"FOUND exact solution (n={n}, k={k}) at gen {generation}, time {elapsed:.2f}s")
                    if output_file is not None:
                        try:
                            write_solution_to_file(output_file, n, k, True, elapsed, generation, best[1], child)
                        except Exception as e:
                            print(f"Warning: failed to write solution to {output_file}: {e}")
                    return child
        pop = newpop
        fitnesses = newfit
        diags = newdiags

    elapsed = time.time() - start
    print(f"Time limit reached. Best diag count found = {best[1]} (wanted {k})")
    if output_file is not None and best is not None:
        try:
            write_solution_to_file(output_file, n, k, False, elapsed, generation, best[1], best[0])
        except Exception as e:
            print(f"Warning: failed to write best solution to {output_file}: {e}")
    return best[0]

# ---------------- Multiprocessing wrapper for batch runs ----------------
def func(args):
    # args can be (n,k) or a dict/tuple; allow passing output filename in args[2]
    if isinstance(args, tuple) and len(args) >= 2:
        n,k = args[0], args[1]
        output_file = args[2] if len(args) >= 3 else None
        # give each worker a distinct seed based on pid/time
        seed = (os.getpid() ^ k) + int(time.time() * 1000) % 100000
        return evolutionary_search(n, k, time_limit=10.0, pop_size=800, seed=seed, output_file=output_file)
    else:
        n = args[0]; k = args[1]
        output_file = args[2] if len(args) >= 3 else None
        seed = (os.getpid() ^ k) + int(time.time() * 1000) % 100000
        return evolutionary_search(n, k, time_limit=10.0, pop_size=800, seed=seed, output_file=output_file)

# ---------------- Example CLI / demo ----------------
def demo_single(output_file=None):
    random.seed(1)
    n = 20
    k = 20  # pick a target; adjust to your experiment
    print(f"Starting single evolutionary search for n={n}, k={k}")
    sol = evolutionary_search(n, k, time_limit=1200.0, pop_size=50, seed=42, output_file=output_file)
    print("Result (first 10 vertices):")
    for i,(x,y) in enumerate(sol[:10]):
        print(i, x, y)
    print("Simple:", is_simple_polygon(sol))
    print("Diagonals inside:", count_interior_diagonals(sol))

def demo_batch(output_file=None):
    # small demonstration tasks; adjust as needed
    tasks = [(j, i, output_file) for j in range(2, 100) for i in range(1, max(1, (j * (j - 3) // 2)) )]
    if process_map is None:
        print("tqdm.contrib.concurrent.process_map not available; running sequentially.")
        results = [func(t) for t in tasks]
    else:
        # process_map will create its own ProcessPool up to max_workers
        results = process_map(func, tasks, max_workers=14)
    # just print diag counts
    for (n,k,_), poly in zip(tasks, results):
        d = count_interior_diagonals(poly)
        print(f"Task n={n}, k={k} -> found diagonals {d}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--demo", choices=["single","batch"], default="single")
    parser.add_argument("--output", "-o", dest="output", default=None,
                        help="append solutions to this file (optional)")
    args = parser.parse_args()
    if args.demo == "single":
        demo_single(output_file=args.output)
    else:
        demo_batch(output_file=args.output)
