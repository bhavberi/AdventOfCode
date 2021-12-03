#DAY 3 PART 2

a=1000
l=list()
d0={1:0,2:0,3:0,4:0,5:0,6:0,7:0,8:0,9:0,10:0,11:0,12:0}
d1={1:0,2:0,3:0,4:0,5:0,6:0,7:0,8:0,9:0,10:0,11:0,12:0}
o=''
c=''
for i in range(a):
    z=input()
    l+=[z,]
l2=l.copy()
for j in range(1,13):
    for i in l:
        if i[j-1]=='0':
            d0[j]+=1
        else:
            d1[j]+=1
    if d0[j]>d1[j]:
        l1=list()
        for i in l:
            if i[j-1]=='0':
                l1+=[i,]
        l=l1
        if len(l1)==1:
            o=l[0]
            break
    else:
        l1=list()
        for i in l:
            if i[j-1]=='1':
                l1+=[i,]
        l=l1
        if len(l1)==1:
            o=l[0]
            break
        
d0={1:0,2:0,3:0,4:0,5:0,6:0,7:0,8:0,9:0,10:0,11:0,12:0}
d1={1:0,2:0,3:0,4:0,5:0,6:0,7:0,8:0,9:0,10:0,11:0,12:0}            
for j in range(1,13):
    for i in l2:
        if i[j-1]=='0':
            d0[j]+=1
        else:
            d1[j]+=1
    if d0[j]<=d1[j]:
        l1=list()
        for i in l2:
            if i[j-1]=='0':
                l1+=[i,]
        l2=l1
        if len(l1)==1:
            c=l2[0]
            break
    else:
        l1=list()
        for i in l2:
            if i[j-1]=='1':
                l1+=[i,]
        l2=l1
        if len(l1)==1:
            c=l2[0]
            break
print()
print(o,c)
print(int(o,2)*int((c),2))
#BHAV BERI
