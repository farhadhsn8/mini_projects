def isID(s):
    if((((ord(s[0]) >= 97)and (ord(s[0]) <= 122)) or ((ord(s[0]) >= 65)and (ord(s[0]) <= 90)))==False ):
        return 0
    for i in range(1,len(s)):
        if((((ord(s[i]) >= 97)and (ord(s[i]) <= 122)) or ((ord(s[i]) >= 65)and (ord(s[i]) <= 90)) or  ((ord(s[i]) >= 48)and (ord(s[i]) <= 57)))==False ):
            return 0
    return 1


table =[
    ['int_kw','int'],
    ['bool_kw','bool'],
    ['float_kw','float'],
    ['class_kw','class'],
    ['func_kw','func'],
    ['arg_kw','()']
]

f = open("t.txt", "r")
x= f.read()
# print(x)
x = x.replace('\n',' ')
x = x.replace('\t',' ')
token = x.split(' ')

# print(token)
# print(ord('Z'))

flag = 0

for i in range(len(token)):
    flag=0
    for j in range(6):
        if (token[i]== table[j][1]):
            print(table[j][0],'      ',token[i])
            flag=1

    if(isID(token[i])==1 and flag==0):
        print('ID','      ',token[i])
        flag=1

    if (flag == 0):
        print("SyntaxError: invalid syntax ==> ",token[i])
        break



