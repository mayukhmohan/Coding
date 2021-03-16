import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

df=pd.read_csv('normal.csv')
df=df.iloc[:,0:1].values
plt.figure()
plt.hist(x=df[:,0],bins=30)

df1=pd.read_csv('uniform.csv')
df1=df1.iloc[:,0:1].values
plt.figure()
plt.hist(x=df1[:,0],bins=50)

df=pd.read_csv('readings_mergesort.csv',header=None)
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
# number_of_samples = 100
# n = np.linspace(0, 65536, number_of_samples)
m=x*np.log2(x)
plt.figure()
plt.xlabel('Size') 
plt.ylabel('No of Operation')
plt.title('Mergesort')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.plot(x, m, label="O(nlogn)")
plt.legend()
df=pd.read_csv('time_merge.csv')
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
plt.figure()
plt.xlabel('Size') 
plt.ylabel('Time')
plt.title('Mergesort Time')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.legend()
df=pd.read_csv('c_mergesort.csv')
#df=df.iloc[:,0:1].values
#plt.hist(x=df[:,0])
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
plt.figure()
plt.xlabel('Size') 
plt.ylabel('value for c')
plt.title('c for Mergesort')
plt.plot(x, y, label="Uniform",marker='o')
plt.plot(w, z, label="Normal",marker='o')
plt.legend()
df=pd.read_csv('swap_merge.csv')
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
# number_of_samples = 100
# n = np.linspace(0, 65536, number_of_samples)
m=x*np.log2(x)
plt.figure()
plt.xlabel('Size') 
plt.ylabel('No of Operation')
plt.title('Mergesort Swap')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.plot(x, m, label="O(nlogn)")
plt.legend()
df=pd.read_csv('comparison_merge.csv')
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
# number_of_samples = 100
# n = np.linspace(0, 65536, number_of_samples)
m=x*np.log2(x)
plt.figure()
plt.xlabel('Size') 
plt.ylabel('No of Operation')
plt.title('Mergesort Comparison')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.plot(x, m, label="O(nlogn)")
plt.legend()



df=pd.read_csv('readings_quicksort.csv')
#df=df.iloc[:,0:1].values
#plt.hist(x=df[:,0])
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
# number_of_samples = 10000
# n = np.linspace(0, 65536, number_of_samples)
m=x*np.log2(x)
plt.figure()
plt.xlabel('Size') 
plt.ylabel('No of Operation')
plt.title('Quicksort')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.plot(x, m, label="O(nlogn)")
plt.legend()
df=pd.read_csv('c_quicksort.csv')
#df=df.iloc[:,0:1].values
#plt.hist(x=df[:,0])
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
plt.figure()
plt.xlabel('Size') 
plt.ylabel('value for c')
plt.title('c for Quicksort')
plt.plot(x, y, label="Uniform",marker='o')
plt.plot(w, z, label="Normal",marker='o')
plt.legend()
df=pd.read_csv('time_quick.csv')
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
plt.figure()
plt.xlabel('Size') 
plt.ylabel('Time')
plt.title('Quicksort Time')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.legend()
df=pd.read_csv('swap_quick.csv')
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
# number_of_samples = 100
# n = np.linspace(0, 65536, number_of_samples)
m=x*np.log2(x)
plt.figure()
plt.xlabel('Size') 
plt.ylabel('No of Operation')
plt.title('Quicksort Swap')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.plot(x, m, label="O(nlogn)")
plt.legend()
df=pd.read_csv('comparison_quick.csv')
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
# number_of_samples = 100
# n = np.linspace(0, 65536, number_of_samples)
m=x*np.log2(x)
plt.figure()
plt.xlabel('Size') 
plt.ylabel('No of Operation')
plt.title('Quicksort Comparison')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.plot(x, m, label="O(nlogn)")
plt.legend()



df=pd.read_csv('readings_bucketsort.csv')
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
# number_of_samples = 100
# n = np.linspace(0, 65536, number_of_samples)
m=x
plt.figure()
plt.xlabel('Size') 
plt.ylabel('No of Operation')
plt.title('Bucketsort')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.plot(x, m, label="O(n)")
plt.legend()
df=pd.read_csv('c_bucketsort.csv')
#df=df.iloc[:,0:1].values
#plt.hist(x=df[:,0])
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
plt.figure()
plt.xlabel('Size') 
plt.ylabel('value for c')
plt.title('c for Bucketsort')
plt.plot(x, y, label="Uniform",marker='o')
plt.plot(w, z, label="Normal",marker='o')
plt.legend()
df=pd.read_csv('time_bucket.csv')
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
plt.figure()
plt.xlabel('Size') 
plt.ylabel('Time')
plt.title('Bucketsort Time')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.legend()
df=pd.read_csv('swap_bucket.csv')
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
# number_of_samples = 100
# n = np.linspace(0, 65536, number_of_samples)
m=x
plt.figure()
plt.xlabel('Size')
plt.ylabel('No of Operation')
plt.title('Bucketsort Swap')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.plot(x, m, label="O(n)")
plt.legend()
df=pd.read_csv('comparison_bucket.csv')
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
# number_of_samples = 100
# n = np.linspace(0, 65536, number_of_samples)
m=x
plt.figure()
plt.xlabel('Size') 
plt.ylabel('No of Operation')
plt.title('Bucketsort Comparison')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.plot(x, m, label="O(n)")
plt.legend()


df=pd.read_csv('readings_rand_quick.csv')
#df=df.iloc[:,0:1].values
#plt.hist(x=df[:,0])
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
# number_of_samples = 100
# n = np.linspace(0, 65536, number_of_samples)
m=x*np.log2(x)
n=x**2
plt.figure()
plt.xlabel('Size') 
plt.ylabel('No of Operation')
plt.title('Randomized Quicksort')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.plot(x, m, label="O(nlogn)")
# plt.plot(x, n, label="O(n2)")
plt.legend()
df=pd.read_csv('c_random_quicksort.csv')
#df=df.iloc[:,0:1].values
#plt.hist(x=df[:,0])
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
plt.figure()
plt.xlabel('Size') 
plt.ylabel('value for c')
plt.title('c for Randomized Quicksort')
plt.plot(x, y, label="Uniform",marker='o')
plt.plot(w, z, label="Normal",marker='o')
plt.legend()
df=pd.read_csv('time_rand_quick.csv')
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
plt.figure()
plt.xlabel('Size')
plt.ylabel('Time')
plt.title('Randomized Quicksort Time')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.legend()
df=pd.read_csv('swap_rand_quick.csv')
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
# number_of_samples = 100
# n = np.linspace(0, 65536, number_of_samples)
m=x*np.log2(x)
plt.figure()
plt.xlabel('Size') 
plt.ylabel('No of Operation')
plt.title(' Randomized Quicksort Swap')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.plot(x, m, label="O(nlogn)")
plt.legend()
df=pd.read_csv('comparison_rand_quick.csv')
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
# number_of_samples = 100
# n = np.linspace(0, 65536, number_of_samples)
m=x*np.log2(x)
plt.figure()
plt.xlabel('Size') 
plt.ylabel('No of Operation')
plt.title('Randomized Quicksort Comparison')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.plot(x, m, label="O(nlogn)")
plt.legend()


df=pd.read_csv('readings_MOM.csv',header=None)
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
# number_of_samples = 100
# n = np.linspace(0, 65536, number_of_samples)
m=x
x=x[:-1]
y=y[:-1]
w=w[:-1]
z=z[:-1]
m=m[:-1]
plt.figure()
plt.xlabel('Size')
plt.ylabel('No of Operation')
plt.title('Median of Medians (Order Statistics)')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.plot(x, m, label="O(n)")
plt.legend()
df=pd.read_csv('c_MOM.csv')
#df=df.iloc[:,0:1].values
#plt.hist(x=df[:,0])
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
plt.figure()
plt.xlabel('Size') 
plt.ylabel('value for c')
plt.title('c for MoM')
plt.plot(x, y, label="Uniform",marker='o')
plt.plot(w, z, label="Normal",marker='o')
plt.legend()
df=pd.read_csv('time_MOM.csv')
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
plt.figure()
plt.xlabel('Size')
plt.ylabel('Time')
plt.title('MoM Time')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.legend()
df=pd.read_csv('swap_MOM.csv')
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
# number_of_samples = 100
# n = np.linspace(0, 65536, number_of_samples)
m=x*np.log2(x)
plt.figure()
plt.xlabel('Size') 
plt.ylabel('No of Operation')
plt.title('MoM Swap')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.plot(x, m, label="O(nlogn)")
plt.legend()
df=pd.read_csv('comparison_MOM.csv')
df1=df.iloc[:,0:2].values
x=df1[:,0]
y=df1[:,1]
df2=df.iloc[:,2:4].values
w=df2[:,0]
z=df2[:,1]
# number_of_samples = 100
# n = np.linspace(0, 65536, number_of_samples)
m=x*np.log2(x)
plt.figure()
plt.xlabel('Size') 
plt.ylabel('No of Operation')
plt.title('MoM Comparison')
plt.plot(x, y, label="Uniform")
plt.plot(w, z, label="Normal")
plt.plot(x, m, label="O(nlogn)")
plt.legend()

df1=pd.read_csv('readings_MOM.csv',header=None)
df2=pd.read_csv('readings_MOM_3.csv',header=None)
df3=pd.read_csv('readings_MOM_7.csv',header=None)
df4=pd.read_csv('readings_MOM_9.csv',header=None)
df_u = [pd.DataFrame(df1.iloc[:,:2].values),pd.DataFrame(df2.iloc[:,1].values),pd.DataFrame(df3.iloc[:,1].values),pd.DataFrame(df4.iloc[:,1].values)]
df_u = pd.concat(df_u,axis=1)
df_u.columns = [0,5,3,7,9]
df_u.plot(x=0, y=[5, 3, 7, 9], kind="bar")