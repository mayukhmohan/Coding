#include<bits/stdc++.h>
using namespace std;
int N;
int util(vector<vector<int>> &cache,vector<int> &v,int l,int r){
    if(l>r)
        return 0;
    
    if(cache[l][r] != -1)
        return cache[l][r];
    
    int year = N - (r-l);

    return cache[l][r] = max(util(cache,v,l+1,r) + v[l] * year,util(cache,v,l,r-1) + v[r] * year);
}
int main()
{
    int n,x;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    N = v.size();
    vector<vector<int>> cache(N,vector<int>(N,-1));
    cout<<util(cache,v,0,N-1)<<endl;
    return 0;
}