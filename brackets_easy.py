open_list = ["[","{","("]
close_list = ["]","}",")"]
def check(myStr):
    stack = []
    for i in myStr:
        if i in open_list:
            stack.append(i)
        elif i in close_list:
            pos = close_list.index(i)
            if ((len(stack) > 0) and
                (open_list[pos] == stack[len(stack)-1])):
                stack.pop()
            else:
                return "NO"
    if len(stack) == 0:
        return "YES"
    else:
        return "NO"
for _ in range(0, int(input())):
    brc = input()
    print(check(brc))