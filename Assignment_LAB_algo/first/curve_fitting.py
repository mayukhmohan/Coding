import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
import pandas as pd

df=pd.read_csv('readings_rand_quick.csv',header=None)
df = df.drop(df.columns[2],axis=1)
X=df[0]
y=df[1]
def func(x,c):
    return c*x*np.log2(x)
c_val=[]
for i in range(len(X)):
    temp=X[:i]
    popt, pcov = curve_fit(func, X, y)
    print("Popt-->coeff", popt[0],"Sq----error",pcov[0][0])
    c_val.append(popt[0])
plt.figure()
plt.plot(X, func(X,*popt), 'r-',label='regression\nfit: c=%5.3f' % tuple(popt))
plt.plot(X,y,'g-',label='Actual')
plt.scatter(x=df[0],y=df[1])
plt.xlabel('Size')
plt.ylabel('No Of Operation')
plt.title('Randomized QuickSort Uniform')
plt.legend()
plt.show()


df=pd.read_csv('readings_quicksort.csv',header=None)
df = df.drop(df.columns[2],axis=1)
X=df[0]
y=df[1]
def func(x,c):
    return c*x*np.log2(x)
c_val=[]
for i in range(len(X)):
    temp=X[:i]
    popt, pcov = curve_fit(func, X, y)
    print("Popt-->coeff", popt[0],"Sq----error",pcov[0][0])
    c_val.append(popt[0])
plt.figure()
plt.plot(X, func(X,*popt), 'r-',label='regression\nfit: c=%5.3f' % tuple(popt))
plt.plot(X,y,'g-',label='Actual')
plt.scatter(x=df[0],y=df[1])
plt.xlabel('Size')
plt.ylabel('No Of Operation')
plt.title('QuickSort Uniform')
plt.legend()
plt.show()

df=pd.read_csv('readings_bucketsort.csv',header=None)
df = df.drop(df.columns[2],axis=1)
X=df[0]
y=df[1]

def func(x,c):
    return c*x

c_val=[]
for i in range(len(X)):
    temp=X[:i]
    popt, pcov = curve_fit(func, X, y)
    print("Popt-->coeff", popt[0],"Sq----error",pcov[0][0])
    c_val.append(popt[0])
plt.figure()
plt.plot(X, func(X,*popt), 'r-',label='regression\nfit: c=%5.3f' % tuple(popt))
plt.plot(X,y,'g-',label='Actual')
plt.scatter(x=df[0],y=df[1])
plt.xlabel('Size')
plt.ylabel('No Of Operation')
plt.title('BucketSort Uniform')
plt.legend()
plt.show()

df=pd.read_csv('readings_MOM.csv',header=None)
df = df.drop(df.columns[2],axis=1)
X=df[0]
y=df[1]

def func(x,c):
    return c*x

c_val=[]
for i in range(len(X)):
    temp=X[:i]
    popt, pcov = curve_fit(func, X, y)
    print("Popt-->coeff", popt[0],"Sq----error",pcov[0][0])
    c_val.append(popt[0])
plt.figure()
plt.plot(X, func(X,*popt), 'r-',label='regression\nfit: c=%5.3f' % tuple(popt))
plt.plot(X,y,'g-',label='Actual')
plt.scatter(x=df[0],y=df[1])
plt.xlabel('Size')
plt.ylabel('No Of Operation')
plt.title('Median of Medians Uniform')
plt.legend()
plt.show()


# NORMAL DIST
df=pd.read_csv('readings_rand_quick.csv',header=None)
df = df.drop(df.columns[2],axis=1)
X=df[0]
y=df[3]

def func(x,c):
    return c*x*np.log2(x)

c_val=[]
for i in range(len(X)):
    temp=X[:i]
    popt, pcov = curve_fit(func, X, y)
    print("Popt-->coeff", popt[0],"Sq----error",pcov[0][0])
    c_val.append(popt[0])
plt.figure()
plt.plot(X, func(X,*popt), 'r-',label='regression\nfit: c=%5.3f' % tuple(popt))
plt.plot(X,y,'g-',label='Actual')
plt.scatter(x=df[0],y=df[3])
plt.xlabel('Size')
plt.ylabel('No Of Operation')
plt.title('Randomized QuickSort Normal')
plt.legend()
plt.show()

df=pd.read_csv('readings_quicksort.csv',header=None)
df = df.drop(df.columns[2],axis=1)
X=df[0]
y=df[3]

def func(x,c):
    return c*x*np.log2(x)

c_val=[]
for i in range(len(X)):
    temp=X[:i]
    popt, pcov = curve_fit(func, X, y)
    print("Popt-->coeff", popt[0],"Sq----error",pcov[0][0])
    c_val.append(popt[0])
plt.figure()
plt.plot(X, func(X,*popt), 'r-',label='regression\nfit: c=%5.3f' % tuple(popt))
plt.plot(X,y,'g-',label='Actual')
plt.scatter(x=df[0],y=df[3])
plt.xlabel('Size')
plt.ylabel('No Of Operation')
plt.title('QuickSort Normal')
plt.legend()
plt.show()

df=pd.read_csv('readings_bucketsort.csv',header=None)
df = df.drop(df.columns[2],axis=1)
X=df[0]
y=df[3]

def func(x,c):
    return c*x

c_val=[]
for i in range(len(X)):
    temp=X[:i]
    popt, pcov = curve_fit(func, X, y)
    print("Popt-->coeff", popt[0],"Sq----error",pcov[0][0])
    c_val.append(popt[0])
plt.figure()
plt.plot(X, func(X,*popt), 'r-',label='regression\nfit: c=%5.3f' % tuple(popt))
plt.plot(X,y,'g-',label='Actual')
plt.scatter(x=df[0],y=df[3])
plt.xlabel('Size')
plt.ylabel('No Of Operation')
plt.title('BucketSort Normal')
plt.legend()
plt.show()

df=pd.read_csv('readings_MOM.csv',header=None)
df = df.drop(df.columns[2],axis=1)
X=df[0]
y=df[3]

def func(x,c):
    return c*x

c_val=[]
for i in range(len(X)):
    temp=X[:i]
    popt, pcov = curve_fit(func, X, y)
    print("Popt-->coeff", popt[0],"Sq----error",pcov[0][0])
    c_val.append(popt[0])
plt.figure()
plt.plot(X, func(X,*popt), 'r-',label='regression\nfit: c=%5.3f' % tuple(popt))
plt.plot(X,y,'g-',label='Actual')
plt.scatter(x=df[0],y=df[3])
plt.xlabel('Size')
plt.ylabel('No Of Operation')
plt.title('Median of Medians Normal')
plt.legend()
plt.show()

