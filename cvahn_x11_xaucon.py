with open("XAUCON.INP", "r") as f:
    search = f.readline().strip()
    key = f.readline().strip()
    # Create a new string that is twice the original to simulate the circular nature
    search += search
indexes = []
for i in range(len(search) // 2):  # Limit the range to the length of the original string
    if search[i:i+len(key)] == key:
        indexes.append(i + 1)
with open("XAUCON.OUT", "w") as f:
    f.write(' '.join(map(str, indexes)))
