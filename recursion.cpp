#include<iostream>
using namespace std;

int power(int n,int p){
    if(p==0)return 1;
    return n*power(n,p-1);
}
int fibonacci(int n){
    if(n==1)return 0;
    if(n==2)return 1;
    int num=fibonacci(n-1)+fibonacci(n-2);
    return num;
}
bool sorted_or_not(int n, int arr[]){
    if(n==1)return true;
    if(arr[n-1]>arr[n-2]){
        return sorted_or_not(n-1,arr);
    }
    return false;
}
int increasing_num(int n){
    if(n==0)return 0;
    cout<<increasing_num(n-1)<<" ";
    return n;
}
int decreasing_num(int n){
   if(n==0)return -1;
   cout<<n<<" ";
   decreasing_num(n-1);
   return n;
}
int firstocc(int arr[],int n,int key,int i){
    if(n==0)return -1;
    if(arr[0]==key)return i;
    return firstocc(arr+1,n-1,key,i+1);
}
int lastocc(int arr[],int n,int key,int i,int var){
    if(n==0)return var;
    if(arr[0]==key)var=i;
    return lastocc(arr+1,n-1,key,i+1,var);
}



int main(){
    // cout<<power(5,3)<<endl;
    // cout<<fibonacci(8)<<endl;
    // int arr[]={-11,2,3,4,5};
    // cout<<sorted_or_not(5,arr)<<endl;
    // cout<<endl;
    // decreasing_num(10);
    int arr[]={1,2,4,5,2,5,21,5,4,32,3};
    cout<<firstocc(arr,11,2,0)<<endl;
    cout<<lastocc(arr,11,2,0,-1)<<endl; 
    return 0;
}