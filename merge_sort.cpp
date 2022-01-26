#include<iostream>
using namespace std;
void merge2(int arr[],int l, int mid, int r){
    int tl=0,tr=r-l,tm=mid-l;
    int a[r-l+1];
    for(int i=0;i<=r-l;i++){
        a[i]=arr[i+l];
    }
    for(int i=0;i<=r-l;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
    for(int i=0;i<=r-l;i++){
        if(tl>mid-l){
            arr[i+l]=a[tm+1];
            tm++;
            continue;
        }
        if(tm+1>r-l){
            arr[i+l]=a[tl];
            tl++;
            continue;
        }
        if(a[tl]<a[tm+1]){
            arr[i+l]=a[tl];
            tl++;
        }else{
            arr[i+l]=a[tm+1];
            tm++;
        }
    }
    for(int i=l;i<=r;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
void merge(int arr[], int l, int mid, int r,int n){
    int tl=l,tr=r,tm=mid;
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=arr[i];
    }
    for(int i=l;i<=r;i++){
        if(tl>mid){
            arr[i]=a[tm+1];
            tm++;
            continue;
        }
        if(tm+1>tr){
            arr[i]=a[tl];
            tl++;
            continue;
        }
        if(a[tl]<a[tm+1]){
            arr[i]=a[tl];
            tl++;
        }else{
            arr[i]=a[tm+1];
            tm++;
        }
    }
    // for(int i=l;i<=r;i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;
    // int tl=0,tr=r-l,tm=mid-l;
    // int a[r-l+1];
    // for(int i=0;i<r-l+1;i++){
    //     a[i]=arr[i+l];
    // }
    // for(int i=0;i<r-l+1;i++){
    //     if(tl>tm){
    //         arr[i+l]=a[tm+1];
    //         tm++;
    //         continue;
    //     }
    //     if(tm+1>tr){
    //         arr[i+l]=a[tl];
    //         tl++;
    //         continue;
    //     }
    //     if(a[tl]<a[tm+1]){
    //         arr[i+l]=a[tl];
    //         tl++;
    //     }else{
    //         arr[i+l]=a[tm+1];
    //         tm++;
    //     }
    // }
}
void mergesort(int arr[], int l, int r,int n){
    if(l<r){
    int mid=(l+r)/2;
    mergesort(arr,l,mid,n);
    mergesort(arr,mid+1,r,n);
    merge(arr,l,mid,r,n);
    // merge2(arr,l,mid,r,n);
    }
}
void mergesort2(int arr[], int l, int r){
    if(l<r){
    int mid=(l+r)/2;
    mergesort2(arr,l,mid);
    mergesort2(arr,mid+1,r);
    // merge(arr,l,mid,r,n);
    merge2(arr,l,mid,r);
    }
}


int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergesort2(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    // cout<<endl;
    // mergesort2(arr,0,n-1);
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    return 0;
}