#include<bits/stdc++.h>
using namespace std;

struct Comp{
    Comp(){}
    ~Comp(){}
    bool operator()(const vector<int>& a, const vector<int>& b){
        return (a[0]*a[0] + a[1]*a[1]) > (b[0]*b[0] + b[1]*b[1]);
    }
};

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

int main(){
    priority_queue<int> pq;
    for(int i = 0; i < 10; i++){
        pq.push(i);
    }

    priority_queue<int> temp = pq;
    while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;
    cout<<"Size of Priority Queue: "<< pq.size();
    cout<<endl;

    priority_queue<int, vector<int>, greater<int>> min_heap;
    for(int i = 0; i < 10; i++){
        min_heap.push(i);
    }

    priority_queue<int, vector<int>, greater<int>> temp_min = min_heap;
    while(!temp_min.empty()){
        cout<<temp_min.top()<<" ";
        temp_min.pop();
    }
    cout<<endl;
    cout<<"Size of Priority Queue: "<< min_heap.size();
    cout<<endl;

    vector<vector<int>> arr = {{1,3},{-2,2}};
    int N = 1;
    vector<vector<int>> ans =  kClosest(arr,N);
    cout<<"[";
    for(int i=0;i<ans.size();i++){
        cout<<"[";
        cout<<ans[i][0]<<","<<ans[i][1];
        cout<<"]";
    }
    cout<<"]"<<endl;

    vector<int> v1 = {20, 30, 40, 25, 15};
    
    make_heap(v1.begin(), v1.end());
    
    cout << "The maximum element of heap is : ";
    cout << v1.front() << endl;

    v1.push_back(50);
      
    push_heap(v1.begin(), v1.end());
      
    cout << "The maximum element of heap after push is : ";
    cout << v1.front() << endl;
      
    pop_heap(v1.begin(), v1.end());
    v1.pop_back();
      
    cout << "The maximum element of heap after pop is : ";
    cout << v1.front() << endl;

    sort_heap(v1.begin(), v1.end());
    
    cout << "The heap elements after sorting are : ";
    for (auto x : v1) 
       cout << x << " ";

    vector<int>::iterator it1;
      
    is_heap(v1.begin(), v1.end())?
    cout << "The container is heap ":
    cout << "The container is not heap";
    cout << endl;
      
    auto it = is_heap_until(v1.begin(), v1.end());
    
    cout << "The heap elements in container are : ";
    for (it1=v1.begin(); it1!=it; it1++)
       cout << *it1 << " ";
    return 0;
}