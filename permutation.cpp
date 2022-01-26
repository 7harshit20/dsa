#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> ans;
void  permute(vector<int> &a,int n){
    permute(a,n-1);
    for(int i=0;i<ans.size();i++){
        ans[i].push_back(a[n-1]);
        for(int j=n-1;j>=0;j--){
            
        }
    }
}
int main(){

    return 0;
}