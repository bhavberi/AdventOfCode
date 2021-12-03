#Day 3 Part 1

a=1000
l=list()
d0={1:0,2:0,3:0,4:0,5:0,6:0,7:0,8:0,9:0,10:0,11:0,12:0}
d1={1:0,2:0,3:0,4:0,5:0,6:0,7:0,8:0,9:0,10:0,11:0,12:0}
e=''
g=''
print(bin(123))
for i in range(a):
    z=input()
    for j in range(1,13):
        if z[j-1]=='0':
            d0[j]+=1
        else:
            d1[j]+=1
print(d0,d1)
for j in range(1,13):
    if d0[j]>d1[j]:
        e+='0'
        g+='1'
    else:
        e+='1'
        g+='0'
print(e,g)
print(int(e,2)*int((g),2))

#BHAV BERI
