with open("bangchucai.inp", "r") as f:
    s = f.read().strip().lower()
chardict = {i:0 for i in 'kelvin'}
for i in s:
    try:
        chardict[i] += 1
    except:
        pass
with open("bangchucai.out", 'w') as f:
    f.write(str(min(chardict[i] for i in chardict)))