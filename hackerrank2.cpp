#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 0;
    int N = 0;
    cin>>T;
    while(T--){
        cin>>N;
        string s;
        cin>>s;
        int ans = 0;
        vector<int> hash(26, -1);
        bool flag = false;
        for(int i = 0; i < N; i++){
            if(hash[s[i] - 'a'] == -1) hash[s[i] - 'a'] = i;
            else{
                ans = max(ans, i - hash[s[i] - 'a'] - 1);
                hash[s[i] - 'a'] = i;
                flag = true;
            }
        }
        if(ans || flag)
            cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}