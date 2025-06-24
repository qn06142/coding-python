import numpy as np
import random
import matplotlib.pyplot as plt
import concurrent.futures
from collections import deque
import tqdm

# --- MODIFIED PARAMETERS ---
# We can afford more generations now due to the faster fitness function
generations = 50
population_size = 50 # Slightly increased population size

# Simulation parameters
grid_size = 41
center = (grid_size // 2, grid_size // 2)
num_blocks = 120 # Increased blocks slightly to make wall-building easier

# --- NEW FITNESS FUNCTION ---
# This function replaces the old, flawed 'simulate_sequence'
def get_fitness(block_grid):
    """
    Calculates the fitness of a static grid layout.
    - A perfect, sealed wall gets a very high score.
    - An imperfect wall's score is the squared distance to the nearest breach.
    A higher score is always better.
    """
    # Step 1: Find all air cells reachable from the center via BFS.
    q = deque([center])
    visited = {center}
    
    # The center itself should not be blocked.
    if block_grid[center] == 1:
        return 0 # Invalid grid, lowest fitness

    while q:
        x, y = q.popleft()
        for dx, dy in ((1,0),(-1,0),(0,1),(-1,0)):
            nx, ny = x+dx, y+dy
            if (
                0 <= nx < grid_size and
                0 <= ny < grid_size and
                (nx, ny) not in visited and
                block_grid[nx, ny] == 0
            ):
                visited.add((nx, ny))
                q.append((nx, ny))

    # Step 2: Define the border and find if any border cells are reachable.
    all_border_cells = set(
        (i, j)
        for i in range(grid_size)
        for j in range(grid_size)
        if i in (0, grid_size - 1) or j in (0, grid_size - 1)
    )
    reachable_border_cells = visited.intersection(all_border_cells)

    # Step 3: Calculate fitness based on whether the wall is perfect or breached.
    if not reachable_border_cells:
        # PERFECT WALL! The center is sealed.
        # The score is the size of the protected area, with a huge bonus.
        # This ensures any complete wall is better than any incomplete one.
        return 10000 + len(visited)
    else:
        # IMPERFECT WALL. The score is the squared distance to the closest breach.
        # This encourages the algorithm to patch the nearest holes first.
        min_dist_sq = min(
            (p[0] - center[0])**2 + (p[1] - center[1])**2
            for p in reachable_border_cells
        )
        return min_dist_sq

def create_individual():
    grid = np.zeros((grid_size, grid_size), dtype=int)
    coords = [(i,j) for i in range(grid_size) for j in range(grid_size) if (i,j) != center]
    if num_blocks > len(coords):
        raise ValueError("num_blocks is larger than the number of available cells.")
    for x,y in random.sample(coords, num_blocks):
        grid[x,y] = 1
    return grid

def crossover(a, b):
    child = np.copy(a)
    mask = np.random.rand(grid_size, grid_size) > 0.5
    child[mask] = b[mask]
    child[center] = 0
    
    ones = list(zip(*np.nonzero(child)))
    diff = len(ones) - num_blocks
    
    if diff > 0:
        removable = [p for p in ones if p != center]
        num_to_remove = min(diff, len(removable))
        for x, y in random.sample(removable, num_to_remove):
            child[x, y] = 0
    elif diff < 0:
        zeros = list(zip(*np.where(child==0)))
        addable = [p for p in zeros if p != center]
        num_to_add = min(-diff, len(addable))
        for x, y in random.sample(addable, num_to_add):
            child[x, y] = 1
    return child

def mutate(ind):
    mutated_ind = ind.copy()
    ones = [p for p in zip(*np.nonzero(mutated_ind)) if p != center]
    zeros = [p for p in zip(*np.where(mutated_ind==0)) if p != center]

    # Use a small mutation rate based on the number of blocks
    mutation_rate = 0.05 
    num_swaps = max(1, int(mutation_rate * num_blocks))

    for _ in range(num_swaps):
        if not ones or not zeros: break
        
        block_to_move = random.choice(ones)
        air_to_fill = random.choice(zeros)

        mutated_ind[block_to_move], mutated_ind[air_to_fill] = 0, 1

        ones.remove(block_to_move)
        zeros.remove(air_to_fill)
        ones.append(air_to_fill)
        zeros.append(block_to_move)
        
    return mutated_ind

def main():
    population = [create_individual() for _ in range(population_size)]
    best_score = -1
    best_grid = None

    print("Starting evolution with a new fitness function to build walls...")
    with concurrent.futures.ProcessPoolExecutor() as executor:
        for gen in range(generations):
            
            # The new fitness function is much faster, but tqdm is still useful.
            desc = f"Generation {gen+1}/{generations}"
            # --- IMPORTANT: We now call get_fitness, not simulate_sequence ---
            scores = list(tqdm.tqdm(executor.map(get_fitness, population), total=len(population), desc=desc))

            current_best_score_in_gen = max(scores) if scores else -1
            if current_best_score_in_gen > best_score:
                best_score = current_best_score_in_gen
                best_grid = population[scores.index(best_score)].copy()
            
            gen_info = f" | Gen Best Score: {current_best_score_in_gen:.0f} | Overall Best: {best_score:.0f}"
            if best_score > 10000:
                gen_info += " (PERFECT WALL FOUND!)"
            print(gen_info)

            sorted_population = [ind for _, ind in sorted(zip(scores, population), key=lambda x: -x[0])]
            selected = sorted_population[:population_size//2]
            
            children = []
            while len(children) < population_size - len(selected):
                if len(selected) < 2:
                    if selected: children.append(mutate(selected[0].copy()))
                    else: children.append(create_individual())
                    continue
                parents = random.sample(selected, 2)
                child = crossover(parents[0], parents[1])
                child = mutate(child)
                children.append(child)
                
            population = selected + children

    print("\nEvolution finished!")
    if best_grid is not None:
        if best_score > 10000:
            print(f"A perfect wall was found! Fitness: {best_score:.0f}")
        else:
            print(f"Best wall found. Fitness (distance score): {best_score:.0f}")
            
        plt.figure(figsize=(8,8))
        plt.imshow(best_grid, cmap='magma', interpolation='nearest')
        plt.scatter([center[1]], [center[0]], color='cyan', s=100, marker='X', label='Human')
        plt.title('Optimized Block Layout')
        plt.legend(loc='upper right')
        plt.axis('off')
        plt.show()
    else:
        print("No solution found.")

if __name__ == "__main__":
    main()