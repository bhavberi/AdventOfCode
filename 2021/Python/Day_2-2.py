#Day 2 Part 2

f=0
d=0
a=1000
aim=0
for i in range(a):
    l=input()
    if 'forward' in l:
        f+=int(l[8])
        d+=aim*int(l[8])
    if 'up' in l:
        aim-=int(l[3])
    
    if 'down' in l:
        aim+=int(l[5])
    
print(f*d)
#Bhav Beri
