A=input
import itertools as B,math as C
D,E=map(int,A().split())
print(sum(D//C.prod(A)if len(A)%2==1 else-D//C.prod(A)for F in[list(int(A)for A in A().split())]for A in B.chain.from_iterable(B.combinations(F,A)for A in range(1,E+1))))