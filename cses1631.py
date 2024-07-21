n = int(input())
a = [int(i) for i in input().split()]
sum_ = sum(a)
max_ = max(a)
if(max_ > (sum_ - max_)):
    print(max_ * 2)
else:
    print(sum_)