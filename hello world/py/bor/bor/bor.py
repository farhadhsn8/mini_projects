import random
suit = ['clubs','diamonds','hearts','spades']
rank=['2','3','4','5','6','7','8','9','10','jack','queen','king','ace']
cards=[]
for i in range(4):
    for j in range(13):
        cards+=[rank[j] +" of "+suit[i]]
for i in range(52):
    print(cards[i])
print("------------------------------------------------------------------------------------------------")
tmp=''
#algorithm shuffle
for i in range(52):
    rr= random.randrange(0,52)
    cards[rr],cards[i]=cards[i],cards[rr] #swap in python
for i in range(52):
    print(cards[i])
print("------------------------------------------------------------------------------------------------")

    
