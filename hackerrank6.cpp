#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 0;
    cin>>T;
    while(T--){
        int N = 0, W = 0;
        cin>>N>>W;
        vector<int> thick;
        int sumThick = 0;
        for(int i=0;i<N;i++){
            int temp;
            cin>>temp;
            sumThick += temp;
            thick.push_back(temp);
        }
        int restSum = sumThick - W;
        if(restSum <= 0) {
            cout<<"YES"<<endl;
            continue;
        }
        bool subset[N + 1][restSum + 1]; 
        for (int i = 0; i <= N; i++) 
            subset[i][0] = true; 
        for (int i = 1; i <= restSum; i++) 
            subset[0][i] = false; 
        for (int i = 1; i <= N; i++) { 
            for (int j = 1; j <= restSum; j++) { 
                if (j < thick[i - 1]) 
                    subset[i][j] = subset[i - 1][j]; 
                if (j >= thick[i - 1]) 
                    subset[i][j] = subset[i - 1][j] 
                                || subset[i - 1][j - thick[i - 1]]; 
            } 
        } 
        if(subset[N][restSum]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}