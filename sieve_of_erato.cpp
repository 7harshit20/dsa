#include<iostream>
#include<vector>
using namespace std;

int spf(int n){
    int arr[n+1]={0};
    for(int i=2;i<n+1;i++){
        arr[i]=i;
    }
    for(int i=2; i<n+1;i++){
       if(arr[i]==i){
           for(int j=i*i;j<n+1;j+=i){
               if(arr[j]==j){
                   arr[j]=i;
               }
           }
       }
    }
    return arr[n];
}
int main(){
         
    // seive of erato 
    // int n;
    // cin>>n;
    // bool status[n]={1};
    // for(int i=0;i<n;i++){
    //     status[i]=1;
    // }status[0]=0;status[1]=0;
    // for(int i=0;i<n;i++){
    //     if(status[i]){
    //         for(int j=i*i;j<n;j+=i){
    //             status[j]=0;
    //         }
    //     }else continue;
    // }
    // for(int i=0;i<n;i++){
    //     if(status[i])cout<<i<<" ";
    // }



    // prime factorisation using erato 
    int n;
    cin>>n;
    // while (n!=1)
    // {
    //     cout<<spf(n)<<"*";
    //     n=n/spf(n);
    // }
    // cout<<"1";
    return 0;
}