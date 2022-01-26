#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> ans;
void swap(int* a, int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void permute(vector<int> &a,int index){ 
    if(index==a.size()){
        ans.push_back(a);
        return;
    }

    for(int i=index;i<a.size();i++){
        if(i!=index && a[index]==a[i])continue;
        swap(&a[index],&a[i]);
        permute(a,index+1);
        swap(&a[index],&a[i]);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &ele:a)
        cin>>ele;
    permute(a,0);
    for(auto v:ans){
        for(auto ele:v)
            cout<<ele<<" ";
            cout<<endl;
    }
    return 0;
}