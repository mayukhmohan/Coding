#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        vector<int> A, B;
        
        for(int i=0;i<a.length();i++) A.push_back(a[i] - '0');
        for(int i=0;i<b.length();i++) B.push_back(b[i] - '0');
        
        int carry = 0;
        vector<int> sum;
        
        int i = A.size()-1, j = B.size()-1;
        while(i>=0 && j>=0){
            sum.insert(sum.begin(),(A[i] + B[j] + carry)%2);
            carry = (A[i] + B[j] + carry)/2;
            i--;
            j--;
        }
        if(i>=0){
            while(i>=0){
                sum.insert(sum.begin(),(A[i] + carry)%2);
                carry = (A[i] + carry)/2;
                i--;
            }
        }
        else if(j>=0){
            while(j>=0){
                sum.insert(sum.begin(),(B[j] + carry)%2);
                carry = (B[j] + carry)/2;
                j--;
            }
        }
        if(carry){
            sum.insert(sum.begin(),carry);
        }
        string ans = "";
        for(int i=0;i<sum.size();i++){
            ans += sum[i] + '0';
        }
        return ans;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a = "11", b = "1";
    Solution S;
    cout<<S.addBinary(a, b)<<endl;
    return 0;
}