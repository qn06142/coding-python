#!/usr/bin/env python3
# live_triangle_solver.py
# Usage:
#   echo "12 30" | python3 live_triangle_solver.py
# or:
#   python3 live_triangle_solver.py 12 30
#
# Prints count and each solution as a line of n integers (positions 0..n-1),
# in the same layout as your OR-Tools model:
#   side1 = positions[0:k]
#   side2 = positions[k-1:2*k-1]
#   side3 = positions[2*k-2:] + [positions[0]]

import sys
import itertools

def solve(n, T, stop_after_first=False):
    if n % 3 != 0:
        return []

    k = n // 3 + 1
    nums = list(range(1, n+1))
    total = sum(nums)

    # index ranges for inner positions (ordered)
    side1_inner_idx = list(range(1, k-1))         # positions[1 .. k-2]
    side2_inner_idx = list(range(k, 2*k-2))       # positions[k .. 2*k-3]
    side3_inner_idx = list(range(2*k-1, n))       # positions[2*k-1 .. n-1]

    inner_count = k-2  # size of each side's inner block

    solutions = []

    # Precompute all combinations of size inner_count for the whole numbers set,
    # grouped by (frozenset of values) and sum? We'll compute per-remaining-set.
    # Iterate combinations of 3 vertices (combinations, then permutations for assignments)
    for verts in itertools.combinations(nums, 3):
        remaining_after_verts = [x for x in nums if x not in verts]

        # try each assignment (a,b,c) = vertices for positions 0, k-1, 2k-2
        # to respect side sums ordering
        for (a, b, c) in itertools.permutations(verts, 3):
            s1_target = T - a - b  # sum needed for side1 inner numbers
            s2_target = T - b - c
            s3_target = T - c - a

            # quick checks: targets must be achievable by inner_count numbers from remaining
            if s1_target < 0 or s2_target < 0 or s3_target < 0:
                continue
            if s1_target + s2_target + s3_target != sum(remaining_after_verts):
                # If totals don't match something's wrong; skip
                continue

            # Build map from sum -> list of combos of size inner_count from remaining
            # To reduce work, we only build combos for sums equal to s1_target or s2_target.
            # Enumerate combos for group1 (side1 inner)
            # Note: inner_count small (e.g., 3 when n=12), so combinations are cheap.
            found_for_this_vertices = False
            for group1 in itertools.combinations(remaining_after_verts, inner_count):
                if sum(group1) != s1_target:
                    continue
                rem_after_g1 = [x for x in remaining_after_verts if x not in group1]

                for group2 in itertools.combinations(rem_after_g1, inner_count):
                    if sum(group2) != s2_target:
                        continue
                    group3 = [x for x in rem_after_g1 if x not in group2]
                    # group3 must have inner_count items and correct sum (should hold)
                    if len(group3) != inner_count or sum(group3) != s3_target:
                        continue

                    # Now we have partition: group1, group2, group3 and fixed vertices a,b,c
                    # Permute inner placements (positions are ordered), so enumerate permutations
                    # For each permutation of each group's elements, build full positions list
                    for perm1 in itertools.permutations(group1):
                        for perm2 in itertools.permutations(group2):
                            for perm3 in itertools.permutations(group3):
                                positions = [None] * n
                                # vertices
                                positions[0] = a
                                positions[k-1] = b
                                positions[2*k-2] = c
                                # side1 inner -> indices side1_inner_idx
                                for idx, val in zip(side1_inner_idx, perm1):
                                    positions[idx] = val
                                # side2 inner
                                for idx, val in zip(side2_inner_idx, perm2):
                                    positions[idx] = val
                                # side3 inner
                                for idx, val in zip(side3_inner_idx, perm3):
                                    positions[idx] = val

                                # final check (defensive)
                                side1 = positions[0:k]
                                side2 = positions[k-1:2*k-1]
                                side3 = positions[2*k-2:] + [positions[0]]
                                if sum(side1) == T and sum(side2) == T and sum(side3) == T:
                                    solutions.append(positions.copy())
                                    if stop_after_first:
                                        return solutions
                    found_for_this_vertices = True
    return solutions

def main(argv):
    sols = solve(n, T, stop_after_first=False)
    if not sols:
        print("-1")
        return
    print(len(sols))
    for s in sols:
        print(" ".join(map(str, s)))

if __name__ == "__main__":
    main(sys.argv)
