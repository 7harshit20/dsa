#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool islarge(string a,string b){
    return stoi(a+b)>stoi(b+a);
}
void merge(vector<string> &arr,int l,int mid,int r){
    vector<string> tarr(r-l+1);
    int tl=0,tmid=mid-l,tr=r-l;
    for(int i=0;i<r-l+1;i++){
        tarr[i]=arr[i+l];
    }
    for(int i=0;i<r-l+1;i++){
        if(tmid+1>r-l){
            arr[i+l]=tarr[tl];
            tl++;
            continue;
        }
        if(tl>mid-l){
            arr[i+l]=tarr[tmid+1];
            tmid++;
            continue;
        }
        if(  islarge(tarr[tl],tarr[tmid+1])  ){
            arr[i+l]=tarr[tmid+1];
            tmid++;
        }
        else{
            arr[i+l]=tarr[tl];
            tl++;
        }
    }
}
void mergesort(vector<string> &arr,int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
string printLargest(vector<string> &arr){
    mergesort(arr,0,arr.size()-1);
    string ans;
    for(int i=arr.size()-1;i>=0;i--){
        ans+=arr[i];
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<string> v(n);
    for(auto &i:v){
        cin>>i;
    }
    // for(auto ele:v)
    // cout<<ele<<" ";
    cout<<endl;
    // cout<<islarge("30","3")<<endl;
    cout<<printLargest(v); 
    return 0;
}