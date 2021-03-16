#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unsigned long long int T;
    unsigned long long int N;
    cin>>T;
    while(T--){
        cin>>N;
        unsigned long long int result = 0;
        vector<unsigned long long int> arr;
        for(unsigned long long int i=0;i<N;i++){
            unsigned long long int x;
            cin>>x;
            arr.push_back(x);
            if(i!=0) result += ((arr[i]>=arr[i-1]) ? (arr[i] - arr[i-1] - 1) : (arr[i-1] - arr[i] - 1));
        }
        cout<<result<<endl;
    }
    return 0;
}