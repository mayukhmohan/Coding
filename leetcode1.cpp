#include<bits/stdc++.h>
using namespace std;
class Solution {
    #define d 256 
    long int q  = 1e7 + 7;
    vector<long int> power;
    string rabin_karp(string t, long int l){
        if(l == 0) return "";
        long int hash = 0;
        long int N = t.length();
        unordered_map<long int, vector<long int>> m; //map index of string for same hash value
        for(long int i = 0; i < l; i++){
            hash = (hash * d + (t[i] - 'a'))%q;
            m[hash].push_back(0);
        }
        for(long int i=0;i<(N - l);i++){
            hash = ((d * (hash - (t[i] - 'a') * power[l-1]) + (t[i+l] - 'a'))%q + q)%q;
            if(m.find(hash) == m.end()) m[hash].push_back(i+1);
            else{
                for(long int index: m[hash]) {
                    if(t.substr(index, l) == t.substr(i+1, l))  return t.substr(index, l);
                }
                m[hash].push_back(i+1);
            }
        }
        return "";
    }
public:
    string longestDupSubstring(string S) {
        long int l = 0, N = S.length(), r = N - 1;
        for(long int i=0;i<N;i++){
            power.push_back(0);
            power[i] = (i==0) ? 1 : (d * power[i-1])%q;
        }
        string res = "";
        while(l<=r){
            long int m = l + (r - l)/2;
            string ans = rabin_karp(S,m);
            if(ans.length()>res.length()){
                res = ans;
                l = m + 1;
            }
            else r = m - 1; 
        }
        return res;
    }
};
int main(){
    string S = "geeksforgeeks";
    Solution* obj = new Solution();
    int T = 1;
    while(T--){
        cout<<obj->longestDupSubstring(S)<<endl;
    }
    return 0;
}