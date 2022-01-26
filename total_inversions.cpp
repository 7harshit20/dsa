#include<iostream>
using namespace std;

long long int merge(long long arr[],long long l,long long mid,long long r){
    long long int inv=0;
    long long tarr[r-l+1];
    long long tl=0,tmid=mid-l,tr=r-l;
    for(long long i=0;i<r-l+1;i++){
        tarr[i]=arr[i+l];
    }
    for(long long i=0;i<r-l+1;i++){
        if(tl>mid-l){
            arr[i+l]=tarr[tmid+1];
            tmid++;
            continue;
        }
        if(tmid+1>r-l){
            arr[i+l]=tarr[tl];
            tl++;
            continue;
        }
        if(tarr[tl]>tarr[tmid+1]){
            inv+=mid-l-tl+1;
            arr[i+l]=tarr[tmid+1];
            tmid++;
        }
        else{
            arr[i+l]=tarr[tl];
            tl++;
        }
    }
    return inv;
}
long long int mergesort(long long arr[],long long l,long long r){
    long long int a=0;
    if(l>=r) return 0;
    long long mid=(l+r)/2;
    a+=mergesort(arr,l,mid);
    a+=mergesort(arr,mid+1,r);
    a+=merge(arr,l,mid,r);
    return a;
}

int main(){
    long long n;
    cin>>n;
    long long int arr[n];
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<mergesort(arr,0,n-1)<<endl;
    for(long long i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}