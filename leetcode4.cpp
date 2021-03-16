#include<bits/stdc++.h>
using namespace std;
class Solution {
    int partition(vector<vector<int>>& v, int index, int l, int r) {
        vector<int> temp = v[r];
        v[r] = v[index];
        v[index] = temp;
        int store_index = l;
        for(int i=l;i<r;i++){
            if(v[i][1]<v[r][1])
            {
                temp = v[i];
                v[i] = v[store_index];
                v[store_index] = temp;
                store_index++;
            }
        }
        temp = v[r];
        v[r] = v[store_index];
        v[store_index] = temp;
        return store_index;
    }
    
    void quickselect(vector<vector<int>>& v, int l, int r, int pivot_expected){
        if(l == r) return;
        int index = rand()%(r - l + 1) + l; ///////////////////
        int pivot_came = partition(v, index, l, r);
        if(pivot_came == pivot_expected) return;
        else if(pivot_came < pivot_expected) quickselect(v, pivot_came+1, r, pivot_expected);
        else if(pivot_came > pivot_expected) quickselect(v, l, pivot_came-1, pivot_expected);
    }
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<vector<int>> v;
        for(auto it:m){
            vector<int> temp = {it.first, it.second};
            v.push_back(temp);
        }
        int N = v.size();
        quickselect(v, 0, N - 1, N - k);  
        vector<int> ans;
        for(int i=N-k;i<N;i++)
            ans.push_back(v[i][0]);
        return ans;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> v = {1,1,1,2,2,3};
    int k = 2;
    Solution S;
    vector<int> ans = S.topKFrequent(v, k);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}