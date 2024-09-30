import subprocess
import sys

def run_command(command):
    result = subprocess.run(command, input=sys.stdin.read(), text=True, capture_output=True)
    return result.stdout.strip()

command1 = input().strip().split()
command2 = input().strip().split()

output1 = run_command(command1)
output2 = run_command(command2)

if output1 == output2:
    print("PASSED")
else:
    print("FAILED")
    sys.exit(1)
