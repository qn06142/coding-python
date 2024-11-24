with open("TG.INP", "r") as f:
	cases = [int(f.readline()) for i in range(0, int(f.readline()))]
ans = ""
def solve(time):
	if time < 60:
		return "08:" + "0" +str(time) if time < 10 else "08:" + str(time)
	if time == 60:
		return "09:00"
	if time > 60:
		out = str(8 + time // 60) if time >= 600 else "0" + str(8 + time // 60)
		out += ":"
		out += str(time % 60) if time % 60 >= 10 else "0" + str(time % 60)
		return out
for i in cases:
	ans += str(solve(i)) + "\n"
with open("TG.OUT", "w") as f:
	f.write(ans)