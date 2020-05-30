#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr);
    int n,l,r,x,y;
    cin>>n>>l>>r>>x;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        cin>>y;
        arr.push_back(y);
    }
    int anscount = 0;
    int sum = 0;
    int simplest = INT_MAX;
    int hardest = 0;
    for(int i=0;i<(1<<n);i++)
    {
        sum = 0;
        simplest = INT_MAX;
        hardest = 0;
        for(int j=0;j<n;j++)
        {
            if(i & (1<<j))
            {
                sum += arr[j];
                if(simplest>arr[j]) simplest = arr[j];
                if(hardest<arr[j]) hardest = arr[j];
            }
        }
        if(sum<=r && sum>=l && (hardest-simplest)>=x)
            anscount++;
    }
    cout<<anscount<<endl;
    return 0;
}