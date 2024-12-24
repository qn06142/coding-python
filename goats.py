def count_goats():
    goats = input()

    left_goats = 0
    right_goats = 0
    for goat in goats:
        if goat == '>':
            right_goats += 1
        elif goat == '<' and right_goats > 0:
            right_goats -= 1
        else:
            left_goats += 1

    print(str(left_goats + right_goats))

count_goats()
