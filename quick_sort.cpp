#include<iostream>
using namespace std;

void swap(int* a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int partision(int arr[],int l,int r){
    int end=r,i=l,start=l,pivot=arr[r];
    while(end>=i){
        if(arr[i]>pivot){
            swap(&arr[i],&arr[end]);
            end--;
        }
        if(arr[i]<pivot){
            swap(&arr[i],&arr[start]);
            start++;
            i++;   
        }
        else{
            i++;
        }
    }
    // for(int i=l;i<=r;i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;
    for(int k=l;k<=r;k++){
        if(arr[k]==pivot)return k;
    }
    return -1;
}
void quicksort(int arr[],int l, int r){
   if(l<r){
    int pi=partision(arr,l,r);
    quicksort(arr,l,pi-1);
    quicksort(arr,pi+1,r);
   }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}