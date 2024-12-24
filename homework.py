from itertools import product

def solve_tasks_brute_force(n, m, k, task_types, a, b):
    # Helper function to calculate total time for a given task assignment
    def calculate_time(assignment):
        # Last task completed by each person for each type
        last_completed_by_ti = [-1] * (m + 1)
        last_completed_by_teo = [-1] * (m + 1)
        total_time = 0
        ti_count = 0  # Consecutive tasks for Ti
        teo_count = 0  # Consecutive tasks for Teo

        for i, task in enumerate(assignment):
            task_type = task_types[i]
            if task == 0:  # Task assigned to Ti
                if ti_count > k:  # Constraint violated
                    return float('inf')
                # Calculate time
                if last_completed_by_ti[task_type] == 0:
                    total_time += b[task_type - 1]
                else:
                    total_time += a[task_type - 1]
                # Update last completed and reset Teo's counter
                last_completed_by_ti[task_type] = 0
                last_completed_by_teo[task_type] = -1
                ti_count += 1
                teo_count = 0
            else:  # Task assigned to Teo
                if teo_count > k:  # Constraint violated
                    return float('inf')
                # Calculate time
                if last_completed_by_teo[task_type] == 1:
                    total_time += b[task_type - 1]
                else:
                    total_time += a[task_type - 1]
                # Update last completed and reset Ti's counter
                last_completed_by_teo[task_type] = 1
                last_completed_by_ti[task_type] = -1
                teo_count += 1
                ti_count = 0

        return total_time

    # Generate all possible assignments (2^n combinations)
    min_time = float('inf')
    for assignment in product([0, 1], repeat=n):
        min_time = min(min_time, calculate_time(assignment))

    return min_time


n, m, k = map(int, input().split())
task_types = list(map(int, input().split()))
a = list(map(int, input().split()))
b = list(map(int, input().split()))

result = solve_tasks_brute_force(n, m, k, task_types, a, b)
print(result)