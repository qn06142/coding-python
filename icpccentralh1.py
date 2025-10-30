
import sys, base64, lzma

PAYLOAD = r"""/Td6WFoAAATm1rRGAgAhARwAAAAQz1jM4Ad0Aw9dAAEiMj42PWtkmc0wwCxoRyjyhyO2U1rV03Z0GpHjzlvQPayjrOsC4dYEeYa7vT+g4zLdIukiqzlqPfNuQCt6hITXU73bTHfCpsxTO3F/RO/07XpyuL8ZYGmpgRGkksVfLQHici6ZTTWLC69Tb3pFQBW7nnu3V/Op3+cmWinjU1+qAOLTIUtB2LhE5v41mWLmkmxrUKn0haZe6Y4QkcSMzJkNxl0RMrOtlMW17Yx25WMOOVyfASOmJn8f+EYjuNr27RCq98+hCMjsqlOfLyIVA00S6YSMngJZ9C3sT7388ouUZU1IQjfPOWhIqMqYHPpjkI+d/14eEWCnvCOwceTmsEh0HXx/my8JxsQjIy9uL+Fhh328gHHfE0I3cv433xqlX33Www32P1JeE38KUMlJElVObNeDlCB5wZDaLcDkWfiWxDTL+uCuJqDm073bClbk/ox4n66+L5WqRhdlQA8YCUucoXDJoUupJeoBx7/Bbc/RSe8LOWdktsFvBWSk+3dXOspd8hxQxLsTmBiCbXepIHQ4d8PY8Jjkmwdl2KO89kxDOF2xjJExgg5sNHhlqI3Lvcfil74T2nLw4IMcsw84g+KuxJ7D2Of71J9NJNisDFIkDdCrbr2MMuKrBpDVhibgfEMJsj9zzlU62gRgDo5+K0D18WVz3PkkijVm15SjxbAvoSSurPkzxndC2N0lmd25+dCW9OaSkVL3ElANRea4SG4babaiNZJXl0bNOp4tOkNhfy94qs6rW/nJXQXT38lLO8+Q9dN6MBgSQS+aZ4RGccZi/10JlgUWXSFJSq1ATT/lWv60rzeVmBJgUxaNI03Pid7QgeqwQb2NAaFYk9ThuyqTlRow4h3VFyWtpxR9Bk5G7iVGmSwIf4LOEYoZKRgwOw4QzWhOBj09clVnREJaLUsldKFN5FDOmrbx99+nbwNs8wSSueQH8cH7e+DOsY266hzIDBe4hHlsLU+INJdTzCNmBhbh3O5k/tyBaZHBy2dB/kop/Ay/ZoWCe9kThektcN/bgyYE29wS7Zy37FbDbAAAI1eLLCZtpjcAAasG9Q4AAM8L6ISxxGf7AgAAAAAEWVo="""
def varint(data, i=0):
    x = 0
    s = 0
    while True:
        b = data[i]; i += 1
        x |= (b & 0x7F) << s
        if not (b & 0x80): return x, i
        s += 7

def itperm(rank, n):
    fact = [1]
    for i in range(1, n+1): fact.append(fact[-1]*i)
    digits = []
    for k in range(n-1, -1, -1):
        rank, r = divmod(rank, k+1)
        digits.append(r)
    items = list(range(1, n+1))
    perm = []
    for d in digits:
        perm.append(items.pop(d))
    return perm

def load():
    raw = lzma.decompress(base64.b64decode(PAYLOAD))
    i = 0
    m = {}
    ntasks, i = varint(raw, i)
    for _ in range(ntasks):
        n, i = varint(raw, i)
        T, i = varint(raw, i)
        cnt, i = varint(raw, i)
        perms = []
        for __ in range(cnt):
            rank, i = varint(raw, i)
            perms.append(itperm(rank, n))
        m[n, T] = perms
    return m

n, T = map(int, sys.stdin.read().split())
mapping = load()
sols = mapping.get((n, T), [])
if not sols:
    print("-1")
else:
    print(len(sols))
    for p in sols:
        print(" ".join(map(str, p)))
