#include<bits/stdc++.h>
using namespace std;
int getsum(int n) 
{ 
    int sum; 
  
    for (sum = 0; n > 0; sum += n % 10, n /= 10); 
  
    return sum; 
} 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    int N;
    cin>>T;
    int A, B;
    while(T--){
        cin>>N;
        A = 0, B = 0;
        while(N--){
            int X, Y;
            cin>>X>>Y;
            int W = getsum(X);
            int V = getsum(Y);
            if(W>V) A++;
            else if(V>W) B++;
            else A++,B++;
        }
        if(A>B) cout<<"0 "<<A<<endl;
        else if(B>A) cout<<"1 "<<B<<endl;
        else cout<<"2 "<<A<<endl;
    }
    return 0;
}