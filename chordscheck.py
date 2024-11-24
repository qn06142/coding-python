import subprocess
import sys
from random import randint
def testgen():
    n = randint(1, 4)
    arcs = []
    for _ in range(n):
        a, b = randint(1, 10), randint(1, 10)
        if a > b:
            a, b = b, a
        arcs.append((a, b))
    test = str(n) + '\n'
    for i in range(n):
        test += str(arcs[i][0]) + ' ' + str(arcs[i][1]) + '\n'
    return test
def run_command(command):
    result = subprocess.run(command, input=test, text=True, capture_output=True)
    return result.stdout.strip()

command1 = ['python3', 'chordsbrute.py']
command2 = ['python', 'chords.py']
output1 = ''
output2 = ''
test = testgen()
while output1 == output2:
    test = testgen()
    output1 = run_command(command1)
    output2 = run_command(command2)

print("FAILED")
print(test)
print("correct output:")
print(output1)
print("incorrect output:")
print(output2)
sys.exit(1)
