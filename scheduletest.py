import random
import itertools
import copy

# Set random seed for reproducibility
random.seed(42)

# Configuration
num_tasks = 1000
num_cores = 100
tasks = [random.randint(10, 100) for _ in range(num_tasks)]
tasks += [random.randint(1000, 10000) for _ in range(num_tasks // 10)]
# Greedy heuristic (approximate CFS load balancing)
def greedy_load_balance(tasks, num_cores):
    sorted_tasks = sorted(enumerate(tasks), key=lambda x: x[1], reverse=True)
    core_loads = [0] * num_cores
    assignment = [None] * len(tasks)
    for task_idx, task_length in sorted_tasks:
        min_core = core_loads.index(min(core_loads))
        assignment[task_idx] = min_core
        core_loads[min_core] += task_length
    return assignment, core_loads, max(core_loads)

# Compute optimal assignment via brute force (ILP equivalent)
def brute_force_optimal(tasks, num_cores):
    best_makespan = float('inf')
    best_assignment = None

    for assign_tuple in itertools.product(range(num_cores), repeat=len(tasks)):
        core_loads = [0] * num_cores
        for t_idx, core_idx in enumerate(assign_tuple):
            core_loads[core_idx] += tasks[t_idx]
        makespan = max(core_loads)
        if makespan < best_makespan:
            best_makespan = makespan
            best_assignment = list(assign_tuple)
    return best_assignment, best_makespan

# Time-bounded local improvement (Anytime algorithm)
def time_bounded_schedule(tasks, num_cores, init_assignment, time_budget_iters=20000):
    assignment = init_assignment.copy()
    core_loads = [0] * num_cores
    for t_idx, core_idx in enumerate(assignment):
        core_loads[core_idx] += tasks[t_idx]
    current_makespan = max(core_loads)
    
    best_assignment = assignment.copy()
    best_makespan = current_makespan

    for _ in range(time_budget_iters):
        # pick two random tasks to swap cores
        t1, t2 = random.sample(range(len(tasks)), 2)
        c1, c2 = assignment[t1], assignment[t2]
        if c1 == c2:
            continue
        
        # simulate swap
        core_loads[c1] -= tasks[t1]
        core_loads[c2] -= tasks[t2]
        core_loads[c1] += tasks[t2]
        core_loads[c2] += tasks[t1]
        new_makespan = max(core_loads)
        
        if new_makespan <= current_makespan:
            # accept swap
            assignment[t1], assignment[t2] = c2, c1
            current_makespan = new_makespan
            if current_makespan < best_makespan:
                best_makespan = current_makespan
                best_assignment = assignment.copy()
        else:
            # revert swap
            core_loads[c1] += tasks[t1]
            core_loads[c2] += tasks[t2]
            core_loads[c1] -= tasks[t2]
            core_loads[c2] -= tasks[t1]
    
    return best_assignment, best_makespan
# Run computations
greedy_assignment, greedy_loads, greedy_makespan = greedy_load_balance(tasks, num_cores)
time_bounded_assignment, time_bounded_makespan = time_bounded_schedule(
    tasks, num_cores, greedy_assignment, time_budget_iters=50000
)

# Helper to display assignment
def display_assignment(assignment):
    cores = [[] for _ in range(num_cores)]
    loads = [0] * num_cores
    for t_idx, core_idx in enumerate(assignment):
        cores[core_idx].append((t_idx, tasks[t_idx]))
        loads[core_idx] += tasks[t_idx]
    return cores, loads

# Display results
print("Task lengths (index: length):")
for idx, length in enumerate(tasks):
    print(f"  Task {idx}: {length}")

print("\nGreedy CFS-like Assignment:")
cores_greedy, loads_greedy = display_assignment(greedy_assignment)
for c in range(num_cores):
    assigned = ", ".join(f"T{t[0]}({t[1]})" for t in cores_greedy[c])
    print(f"  Core {c}: {assigned} | Load: {loads_greedy[c]}")
print(f"  Greedy Makespan: {greedy_makespan}")

print("\nTime-Bounded Assignment (5000 iterations):")
cores_tb, loads_tb = display_assignment(time_bounded_assignment)
for c in range(num_cores):
    assigned = ", ".join(f"T{t[0]}({t[1]})" for t in cores_tb[c])
    print(f"  Core {c}: {assigned} | Load: {loads_tb[c]}")
print(f"  Time-Bounded Makespan: {time_bounded_makespan}")

# Relative improvements
impr_tb_vs_greedy = (greedy_makespan - time_bounded_makespan) / greedy_makespan * 100

print(f"\nRelative improvement (Time-Bounded vs Greedy): {impr_tb_vs_greedy:.2f}%")
