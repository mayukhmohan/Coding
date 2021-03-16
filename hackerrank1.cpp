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
        string s,d;
        cin>>s;
        cin>>d;
        int ans = 0;
        for(int i = 0; i < N; i++){
            int a = s[i] - '0';
            int b = d[i] - '0';
            ans += min(abs(a-b),(10 - abs(a - b)));
        }
        cout<<ans<<endl;
    }
    return 0;
}