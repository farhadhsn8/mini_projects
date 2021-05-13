import random
suit = ['clubs','diamonds','hearts','spades']
rank=['1','3','4','5','6','7','8','9','10','jack','queen','king','ace']
s=random.randrange(0,4)
r=random.randrange(0,13)
print(rank[r]+" of "+suit[s])