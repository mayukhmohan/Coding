#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
struct Comp{
    Comp(){}
    ~Comp(){}
    bool operator()(const vector<int>& a, const vector<int>& b){
        return (a[0]*a[0] + a[1]*a[1]) > (b[0]*b[0] + b[1]*b[1]);
    }
};
public:
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    if(points.size() == 0) return {};
    priority_queue<vector<int>, vector<vector<int>>, Comp> pq;
    vector<vector<int>> res;
    for(auto x:points){
        pq.push(x);
    }
    while(K--){
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}
};
/*class Solution {
    private:
    struct Comp {
        Comp() {}
        ~Comp() {}
        bool operator()(const vector<int>& a, const vector<int>& b) {
            return (a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]);
        }
    };    

    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {

            if (points.size() == 0)
                return {};

            priority_queue< vector<int>, vector<vector<int>>, Comp> pq;
            
            for (auto kv : points) {
                pq.push(kv);
            
                if(pq.size() > K) pq.pop();
            }
            
            vector<vector<int>> res;
            
            while (!pq.empty()) {
            
                res.push_back(pq.top());

                pq.pop();
            }
            
            return res;

        }
    };*/
int main(){
    vector<vector<int>> arr = {{1,3},{-2,2}};
    int N = 1;
    Solution s;
    vector<vector<int>> ans =  s.kClosest(arr,N);
    cout<<"[";
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        cout<<ans[i][0]<<","<<ans[i][1];
        cout<<"]";
    }
    cout<<"]"<<endl;
    return 0;
}