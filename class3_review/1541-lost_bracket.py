s = input()

res = ''
tmp = ''
while s:
    if s[0].isdigit():
        tmp += s[0]
    else:
        res += tmp.lstrip('0')
        tmp = ''
        if s[0] == '+':
            res += s[0]
        elif s[0] == '-':
            res += ')' + s[0] + '('
    s = s[1:]

res += tmp.lstrip('0')
res = '(' + res[:] + ')'
print(eval(res))
