import os
import re
books_name = os.listdir('exclastxt')  #list of books

def seaech_column(word,arr):
    f=-1
    for i in range(0,len(arr)):
        if arr[i][0]==word:
            f=i
    return f




dicti=set()

ignore = ['a', "the", "is" , "an" , "am" , "and" , "are" ,"or","he","she" ,"for" , "you" ,"we" ,"they" , "of" , "to" , "in","not" , "this" , "that" , "it" , "as"]    

for book in books_name:
   print("ketab")
#    print(book)
   f = open("exclastxt/"+ book, "r")
   words = re.sub("[^\w]", " ",  f.read()).split()  
   for w in words :
       if w.lower() not in ignore :
            dicti.add((w.lower(),book))

dicti=list(dicti)


posting=[]

s=[[1,2],[5,6],[7,9],[5,8]]

print(len(dicti))
# print(seaech_column(6,s))

d=0
for a in dicti:
  
    tmp = seaech_column(a[0] , posting)
    if tmp==-1:
        posting.append(a)
    else:
        posting[tmp]=list(  posting[tmp])
        posting[tmp].append(a[1])

        
# print(posting)


while True:
    print("inter word:")
    inp=input(">>")
    index= seaech_column(inp,posting)
    if index == -1:
        print("not found!!")
    else:
        print(posting[index])



   