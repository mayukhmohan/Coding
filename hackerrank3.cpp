#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 0;
    int N = 0, Q = 0;
    cin>>T;
    while(T--){
        cin>>N;
        map<int,bool> Delivery;
        for(int i = 0; i < N; i++){
            int temp;
            cin>>temp;
            Delivery[temp] = true;
        }
        cin>>Q;
        for(int i = 0; i < Q; i++){
            int temp;
            cin>>temp;
            if(Delivery[temp]) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}