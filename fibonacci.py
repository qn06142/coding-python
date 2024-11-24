import matplotlib.pyplot as plt
inp = int(input())
fib = [1,1]
def oneinterfib(val1, val2):
    return val1 + val2
for i in range(2, inp):
    fib.append(oneinterfib(fib[i-1], fib[i-2]))
plt.plot(fib, "o")
plt.show()
