import random
import string
n=8000
m=random.randint(1,n//1.25)
fp=open("random_ssd.txt","w")
res = ''.join(random.choices(string.ascii_uppercase, k=n))
fp.write(res+"\n")
res = ''.join(random.choices(string.ascii_uppercase, k=m))
fp.write(res)
fp.close()
fp=open("random_ssd.txt","r")
x=fp.read()
x=x.split()
print(len(x[0]))
print(len(x[1]))
