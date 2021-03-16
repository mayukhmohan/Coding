#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    int N;
    vector<int> arr = {1, 3, 5, 7}; 
    //cin>>T;
    T = 1;
    N = 4;
    while(T--){
        //cin>>N;
        int result = 0;
        for(int i=0;i<N;i++){
            //int x;
            //cin>>x;
            //arr.push_back(x);
            if(i!=0) result += ((arr[i]>=arr[i-1]) ? (arr[i] - arr[i-1] - 1) : (arr[i-1] - arr[i] - 1));
        }
        cout<<result<<endl;
    }
    return 0;
}