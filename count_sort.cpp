#include<iostream>
using namespace std;

void countsort(int arr[],int n){
    int maxnum=arr[0];
    for(int i=1;i<n;i++){
        maxnum=max(maxnum,arr[i]);
    }
    maxnum+=1;
    int count[maxnum]={0};
    for(int i=0;i<n;i++){
        count[arr[i]]++;
    }
    cout<<endl;
    int j=0;
    for(int i=0;i<maxnum;i++){
        if(count[i]!=0){
            arr[j]=i;
            j++;
            count[i]--;
            i--;
        }
        continue;
    }
}
int main(){
     int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    countsort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}