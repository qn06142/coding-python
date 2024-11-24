from string import ascii_lowercase
def check_expression(s):
	s = s.lower()
	flag = False
	if any(i in s for i in ascii_lowercase):
		flag = True
	open_brackets = s.count('(')
	close_brackets = s.count(')')
	if open_brackets == close_brackets:
		return 'DUNG'
	elif not flag:
		return 'KHONGDUNG'
	else:
		return 'KHONGHOPLE'
with open('KTNGOAC.INP', 'r') as f:
    lines = f.readlines()
with open('KTNGOAC.OUT', 'w') as f:
    for line in lines:
        result = check_expression(line.strip())
        f.write(result + '\n')