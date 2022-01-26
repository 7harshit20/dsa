#include<iostream>
using namespace std;

void maxSubarraySum(int arr[],int n){
    // o of n*2
    // int sum=0,mx=INT_MIN;
    // int sumArray[n];
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //         sum+=arr[j];
    //         mx=max(mx,sum);
    //     }
    //     sumArray[i]=mx;
    //     sum=0;
    // }
    // mx=sumArray[0];
    // for(int i=0;i<n;i++){
    //     mx=max(mx,sumArray[i]);
    // }
    // cout<<mx<<endl;


    // o of n
    int mx=INT_MIN;
    int currentsum=0;
    for(int i=0;i<n;i++){
        currentsum+=arr[i];
        if(currentsum<0){
            currentsum=0;
        }
        mx=max(mx,currentsum);
    }    
    // end of debate;
}
void maxCircularSubarraySum(int arr[],int n){
    int mx=INT_MIN;
    int currentsum=0;
    int i=0,loop=0;
    while(loop<n+1){
        loop++;
        if(i>=n)i=i-n;
        currentsum+=arr[i];
        mx=max(mx,currentsum);
        if(currentsum<0){
            currentsum=0;
            loop=0;
        }   
        i++;
    }
    cout<<mx;
}
void pairSumProblem(int arr[],int n,int s){
    int i=0;
    int j=n-1;
    while(i<j){
        if(arr[i]+arr[j]>s)j--;
        else if(arr[i]+arr[j]<s)i++;
        else {
            cout<<i<<" "<<j;
            break;
        }
    }
}

int main(){
    int n;
    // cout<<"enter the size of array "<<endl;
    cin>>n;
    int arr[n];
    // cout<<"enter the array"<<endl;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    maxCircularSubarraySum(arr,n);
    // int s;
    // cout<<"enter the sum"<<endl;
    // cin>>s;
    // pairSumProblem(arr,n,s);
    return 0;
}