a,r=[[int(x) for x in input().split(' ')] for i in range(2)]
m=min([s/t for s,t in zip(a,r)])
print(" ".join([str(a-r*m) for a,r in zip(a,r)]))