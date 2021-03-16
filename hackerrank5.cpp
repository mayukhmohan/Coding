#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unsigned long long int T = 0;
    unsigned long long int N = 0;
    unsigned long long int K = 0;
    cin>>T;
    while(T--){
        cin>>N>>K;
        vector<unsigned long long int> arr;
        for(unsigned long long int i = 0; i < N; i++){
            unsigned long long int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        unsigned long long int tempxor = 0; 
        for (unsigned long long int i = 0 ; i < K ; i++) 
            tempxor  = tempxor ^ arr[i]; 
   
        unsigned long long int max_xor = tempxor; 
        for (unsigned long long int i = K ; i < N; i++) 
        { 
            tempxor = tempxor ^ arr[i-K]; 
            tempxor = tempxor ^ arr[i]; 
            max_xor = max(max_xor, tempxor); 
        }
        cout<<max_xor<<endl;
    }
    return 0;
}