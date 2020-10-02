def infect(j,infm,n,v,t1):
    for k in range(1,n+1):
        if infm[k]==False and k!=j:
            if v[k]!=v[j]:
                t2=(pos[j]-pos[k])/(v[k]-v[j])
                if t2>=t1:
                    infm[k]=True
                    infect(k,infm,n,v,t2)
t=int(input())
for r in range(t):
    n=int(input())
    v=[int(x) for x in input().split()]
    v.insert(0,0)
    pos=[0]
    if n==3:
        for i in range(1,4):
            pos.append(i)
    else:
        for i in range(1,6):
            pos.append(i)
    infmin=100
    infmax=-1
    for i in range(1,n+1):
        infm=[False for i in range(n+1)]
        infm[i]=True
        for j in range(1,n+1):
            if i!=j and v[i]!=v[j]:
                t1=(pos[j]-pos[i])/(v[i]-v[j])
                if(t1>=0):
                    infm[j]=True
                    infect(j,infm,n,v,t1)
        inf=infm.count(True)
        infmax=max(inf,infmax)
        infmin=min(inf,infmin)
    print(infmin,infmax)