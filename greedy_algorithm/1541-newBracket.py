s = input()

myS = ""
temp = ""
while len(s) != 0:
    if not s[0].isdigit():
        myS += temp.lstrip("0")
        if s[0] == "-":
            myS += ")-("
        elif s[0] == "+":
            myS += "+"
        temp = ""
    else:
        temp += s[0]
    s = s[1:]
myS += temp.lstrip("0")

myS = "(" + myS[:] + ")"
print(eval(myS))
