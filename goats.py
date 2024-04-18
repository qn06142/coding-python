def count_goats():
    # Get the list of goats from the user
    goats = list(input())

    # Initialize counters for goats going left and right
    left_goats = 0
    right_goats = 0

    # Iterate over the list of goats
    for goat in goats:
        if goat == '>':
            left_goats += 1
        else:
            right_goats += 1

        # If there are goats going in both directions, two goats fall off
        if left_goats > 0 and right_goats > 0:
            left_goats -= 1
            right_goats -= 1

    # Return the total number of goats that successfully crossed the bridge
    return left_goats + right_goats

# Test the function
print(count_goats())
