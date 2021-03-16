import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

df=pd.read_csv('readings_rand_quick.csv',header=None)
df = df.drop(df.columns[2],axis=1)
X=df[0]
y=df[1]

a = X**2*(np.log2(X))**2
a_sum = sum(a)
b = X*np.log2(X)
b_sum = sum(b) 
c_sum = b_sum
d_sum = 13

e = X*y*np.log2(X)
e_sum = sum(e)
f_sum = sum(y)

A = [[a_sum,b_sum],
     [c_sum,d_sum]]
B = [[e_sum],
     [f_sum]]

C = np.matrix(A)
D = np.matrix(B)

ans = C.I * D

c1 = ans[0][0]
c1 = np.array(c1)
c1 = c1[0][0]
c2 = ans[1][0]
c2 = np.array(c2)
c2 = c2[0][0]

y_predict = c1*X*np.log2(X)+c2
plt.figure()
plt.plot(X,y_predict,'r-',label = 'c1 = %5.3f\nc0 = %5.3f' % (c1,c2))
plt.plot(X,y,'g-')
plt.scatter(x=df[0],y=df[1])
plt.xlabel('Size')
plt.ylabel('No Of Operation')
plt.title('Randomized QuickSort Uniform')
plt.legend()


df=pd.read_csv('readings_quicksort.csv',header=None)
df = df.drop(df.columns[2],axis=1)
X=df[0]
y=df[1]

a = X**2*(np.log2(X))**2
a_sum = sum(a)
b = X*np.log2(X)
b_sum = sum(b) 
c_sum = b_sum
d_sum = 13

e = X*y*np.log2(X)
e_sum = sum(e)
f_sum = sum(y)

A = [[a_sum,b_sum],
     [c_sum,d_sum]]
B = [[e_sum],
     [f_sum]]

C = np.matrix(A)
D = np.matrix(B)

ans = C.I * D

c1 = ans[0][0]
c1 = np.array(c1)
c1 = c1[0][0]
c2 = ans[1][0]
c2 = np.array(c2)
c2 = c2[0][0]

y_predict = c1*X*np.log2(X)+c2
plt.figure()
plt.plot(X,y_predict,'r-',label = 'c1 = %5.3f\nc0 = %5.3f' % (c1,c2))
plt.plot(X,y,'g-')
plt.scatter(x=df[0],y=df[1])
plt.xlabel('Size')
plt.ylabel('No Of Operation')
plt.title('QuickSort Uniform')
plt.legend()

df=pd.read_csv('readings_bucketsort.csv',header=None)
df = df.drop(df.columns[2],axis=1)
X=df[0]
y=df[1]

a = X**2
a_sum = sum(a)
b = X
b_sum = sum(b) 
c_sum = b_sum
d_sum = 13

e = X*y
e_sum = sum(e)
f_sum = sum(y)

A = [[a_sum,b_sum],
     [c_sum,d_sum]]
B = [[e_sum],
     [f_sum]]

C = np.matrix(A)
D = np.matrix(B)

ans = C.I * D

c1 = ans[0][0]
c1 = np.array(c1)
c1 = c1[0][0]
c2 = ans[1][0]
c2 = np.array(c2)
c2 = c2[0][0]

y_predict = c1*X+c2
plt.figure()
plt.plot(X,y_predict,'r-',label = 'c1 = %5.3f\nc0 = %5.3f' % (c1,c2))
plt.plot(X,y,'g-')
plt.scatter(x=df[0],y=df[1])
plt.xlabel('Size')
plt.ylabel('No Of Operation')
plt.title('BucketSort Uniform')
plt.legend()