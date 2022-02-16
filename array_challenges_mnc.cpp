#include<iostream>
using namespace std;

void swap(int* a, int* b) {
    int temp=*a;
    *a=*b;
    *b=temp;
}
int firstRepeatingElement(int arr[], int n) {
    int numocc[1000];
    int out=INT_MAX;
    for(int i=0;i<1000;i++) {
        numocc[i]=-1;
    }
    for(int i=0;i<n;i++) {
        if(numocc[arr[i]]!=-1) {
            out=min(out, numocc[arr[i]]);

        }
        else numocc[arr[i]]=i;
    }
    return out;
}
void givenSumOfSubarray(int arr[], int n, int s) {
    int sum=0, i=0, j=0;
    while(j!=n && i!=n-1) {
        if(sum==s) {
            cout<<i<<" "<<j-1;
            break;
        }
        else if(sum>s) {
            sum-=arr[i];
            i=i+1;
        }
        else {
            sum+=arr[j];
            j++;
        }
    }
}
int smallestmissingPositiveInteger(int arr[], int n) {
    int num[2001];
    for(int i=0;i<2001;i++) {
        num[i]=0;
    }
    for(int i=0;i<n;i++) {
        num[arr[i]+1000]++;
    }
    for(int i=1001;i<2001;i++) {
        if(num[i]==0)return i-1000;
    }
    return -1;
}
int missingNumber(int arr[], int n) {

    // Your code here
//     bool ispre[n];
//     for(int i=0;i<n;i++){
//         ispre[i]=false;
//     }
//     for(int i=0;i<n;i++){
//         if(arr[i]>0 && arr[i]<n+1)ispre[arr[i]]=true;
//     }
//     for(int i=1;i<n;i++){
//         if(ispre[i]==false){
//             return i;
//     }
// } 
// return n+1;


    int toswap=n-1, i=0;
    bool last=false;
    while(toswap>i) {
        if(arr[i]<=0) {
            swap(&arr[i], &arr[toswap--]);
        }
        else i++;
    }
    for(int j=0;j<n;j++) {
        if(arr[j]<=0) {
            i=j-1;
            break;
        }
    }
    cout<<i<<endl;
    if(abs(arr[0])==i+1) last=true;
    for(int j=0;j<=i;j++) {
        if(abs(arr[j])<=i) {
            arr[abs(arr[j])]=-1*abs(arr[abs(arr[j])]);
        }
        if(abs(arr[j])==i+1) last=true;
    }
    for(int j=0;j<n;j++) {
        cout<<arr[j]<<" ";
    }
    for(int j=1;j<=i;j++) {
        if(arr[j]>0) return j;
    }
    if(last) {
        return i+2;
    }
    return i+1;

}
int main() {
    int n;
    cout<<"enter the size of array\n";
    cin>>n;
    int arr[n];
    cout<<"enter the array\n";
    for(int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }

    // cout<<firstRepeatingElement(arr,n);

    // int s;
    // cout<<"enter the sum of subarray\n";
    // cin>>s;
    // givenSumOfSubarray(arr,n,s);

    cout<<missingNumber(arr, n)<<endl;

    return 0;
}