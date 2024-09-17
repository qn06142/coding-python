import re

def tokenize_block(block):
    # Tokenize the block into sequences of # with length >= 10 and non-# parts
    tokens = []
    parts = re.findall(r'#+|[^#]+', block)

    for part in parts:
        if part.startswith('#') and len(part) <= 5:
            # Append short # sequences (<= 9) to the previous token if it exists
            if tokens and not tokens[-1].startswith('#'):
                tokens[-1] += part
            else:
                tokens.append(part)
        else:
            tokens.append(part)

    return tokens

# Example usage:
commentart = ""
with open("catgirl.txt", 'r') as f:
    commentart = f.read()
tokens = tokenize_block(commentart)

# Read template and process it
with open("templatestor.txt", "r") as f:
    template = f.read()
tokens1 = template.split(sep='\n')

# Wrap each token with '*/' and '/*'
with open("templatestor1.txt", "w") as f:
    #f.write('\n'.join("*/" + i + "/*" for i in tokens1)) // unoptimal
    f.write('\n'.join(i  for i in tokens1))


with open("templatestor1.txt", 'r') as f:
    templatepreped = f.read()

templatetokens = templatepreped.split(sep='\n')

j = 0
complete = False
for ind, i in enumerate(tokens):
    if not i.count('#') == len(i):
        continue
    toadd = '*/'
    while j < len(templatetokens) and len(toadd + templatetokens[j]) + 2 <= len(i):
        toadd += templatetokens[j]
        j += 1
    toadd += '/*'
    tokens[ind] = toadd + i[len(toadd):]
    if(toadd[-2:] != "/*" and toadd):
        print(toadd)
        print(templatetokens[j - 1])
        print(templatetokens[j + 1])
        raise ValueError
    if j >= len(templatetokens):
        complete = True
        break
if j - len(templatetokens):
    raise ValueError("comment block too short")

# Output the final result
result = ''.join(tokens)
print(result)
with open("finaltemplate.cpp", "w") as f:
    f.write("#include<bits/stdc++.h>\n/*" + result[:] + "*/")