#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void percolateUp(vector<int>& v, int val) {
    v.push_back(val);
    int n=v.size()-1;
    while(n>0) {
        int parent=(n+1)/2;
        parent--;
        if(v[n]>v[parent])swap(v[n], v[parent]);
        n=parent;
    }
}

void percolateDown(vector<int>& v, int s, int e) {
    int j=s, n=e;
    while(2*j+2<=n && v[j]<max(v[2*j+1], v[2*j+2])) {
        if(v[2*j+1]>v[2*j+2]) {
            swap(v[j], v[2*j+1]);
            j=2*j+1;
        }
        else {
            swap(v[j], v[2*j+2]);
            j=2*j+2;
        }
    }
    if(2*j+1==n && v[j]<v[2*j+1])swap(v[j], v[2*j+1]);
}

void heapify(vector<int>& v) {
    int n=v.size()-1;
    for(int i=n;i>=0;i--) {
        percolateDown(v, i, n);
    }
}

void heapToSorted(vector<int>& v) {
    int n=v.size()-1;
    for(int i=0;i<v.size();i++) {
        swap(v[0], v[n]);
        percolateDown(v, 0, --n);
    }
}

void heapSort(vector<int>& v) {
    heapify(v);
    heapToSorted(v);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    vector<int> v={ 4,6,1,1,8,9 };
    // heapSort(v);
    // heapify(v);
    // percolateUp(v, 11);

    //STL functions
    // make_heap(v.begin(), v.end());
    // v.push_back(7);
    // push_heap(v.begin(), v.end());
    // for(auto ele: v)cout<<ele<<" ";
    // cout<<endl;
    // pop_heap(v.begin(), v.end());
    // for(auto ele: v)cout<<ele<<" ";

    priority_queue<int, vector<int>> q;
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty()) {
        cout<<q.top()<<" ";
        q.pop();
    }
    return 0;
}