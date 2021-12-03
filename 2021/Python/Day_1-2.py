#Day 1 Part 2
c=0
a=2000
l=list()
for i in range(a):
    l+=[int(input()),]

p=l[0]+l[1]+l[2] #For Comparison
for i in range(1,a-2):
    s=l[i]+l[i+1]+l[i+2]
    if s>p:
        c+=1
    p=s  
    
print(c)
#Bhav Beri
