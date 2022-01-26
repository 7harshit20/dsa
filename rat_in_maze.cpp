#include<iostream>
#include <algorithm>
using namespace std;

bool isSafe(int** arr,int x,int y, int n){
    if(arr[x][y]==1 && x<n && y<n)return true;
    return false;
}
bool ratpath(int** arr, int x,int y,int n,int** sarr){

    if(x== n-1 && y== n-1){
        sarr[x][y]=1;
        return true;
    }

    if(isSafe(arr,x,y,n)){
        sarr[x][y]=1;
        if(ratpath(arr,x+1,y,n,sarr)){
            return true;
        }
        if(ratpath(arr,x,y+1,n,sarr)){
            return true;
        }
        sarr[x][y]=0;
        return false;
    }
    return false;
}

// bool allowed(int** arr,int x,int y,int n){
//     if(arr[x][y]==1 && x<n && y<n){
//         return true;
//     }
//     return false;
// }
// bool rat(int** arr,int x,int y, int n, int** sarr){
//     if(x==n-1 && y==n-1){
//         sarr[x][y]=1;
//         return true;
//     }    
//     if(allowed(arr,x,y,n)){
//         sarr[x][y]=1;
//         if(rat(arr,x+1,y,n,sarr)){
//             return true;
//         }
//         if(rat(arr,x,y+1,n,sarr)){
//             return true;
//         }
//         sarr[x][y]=0;
//         return false;
//     }
//     return false;
// }

int main(){
    int n;
    cin>>n;

    int** arr=new int *[n];
    
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int** sarr=new int *[n];
    for(int i=0;i<n;i++){
        sarr[i]=new int[n];
        for(int j=0;j<n;j++){
            sarr[i][j]=0;
        }
    }
    cout<<endl;
    if(ratpath(arr,0,0,n,sarr)){
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<sarr[i][j]<<" ";
        }cout<<endl;
    }

    // int arr[]={3,1,5,2};
    // int size=sizeof(arr)/sizeof(arr[0]);
    // sort(arr,arr+3);
    // for(int i=0;i<4;i++){
    //     cout<<arr[i]<<" ";
    // }

    }
    return 0;
}