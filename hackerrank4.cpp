#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 0;
    cin>>T;
    while(T--){
        int N = 0;
        cin>>N;
        map<int,int> util;
        for(int i = 0; i < N; i++){
            int s, e;
            cin>>s>>e;
            for(int j = s; j < e; j++)
                util[j]++;
        }
        int ans = -1;
        int count = 0;
        for(auto it:util){
            if(it.second > count){
                count = it.second;
                ans = it.first;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}