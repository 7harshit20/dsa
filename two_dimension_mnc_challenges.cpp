#include <iostream>
using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(){

// int n,m;
// cin>>n>>m;
// int arr[n][m]; 
// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         cin>>arr[i][j];
//     }
// }
// int rstart=0,rend=n-1,cstart=0,cend=m-1;
// while (rstart<=rend && cstart<=cend)
// {
//     for(int i=cstart;i<=cend;i++){
//         cout<<arr[rstart][i]<<" ";
//     }
//     rstart++;
//     for(int i=rstart;i<=rend;i++){
//         cout<<arr[i][cend]<<" ";
//     }
//     cend--;
//     for(int i=cend;i>=cstart;i--){
//         cout<<arr[rend][i]<<" ";
//     }
//     rend--;
//     for(int i=rend;i>=rstart;i--){
//         cout<<arr[i][cstart]<<" ";
//     }
//     cstart++;
//     cout<<endl;
// }

// int n,m;
// cin>>n>>m;
// int arr[n][m]; 
// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         cin>>arr[i][j];
//     }
// }
// for(int i=0;i<n;i++){
//     for(int j=0;j<i;j++){
//         swap(arr[i][j],arr[j][i]);
//     }
// }
// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         cout<<arr[i][j]<<" ";
//     }
//     cout<<endl;
// }

// int n,m,p;
// cin>>n>>m;
// cin>>p;
// int arr[n][m]; 
// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         cin>>arr[i][j];
//     }
// }
// int arr2[m][p];
// for(int i=0;i<m;i++){
//     for(int j=0;j<p;j++){
//         cin>>arr[i][j];
//     }
// }
// int mularr[n][p];
// for(int i=0;i<n;i++){
//     for(int j=0;j<p;j++){
//         mularr[i][j]=0;
//     }
// }
// for(int i=0;i<n;i++){
//     for(int j=0;j<p;j++){
//         for(int k=0;k<m;k++){
//             mularr[i][j] += (arr[i][k]*arr2[k][j]);
//             cout<<mularr[i][j]<<" ";
//         }
//     }
// }
// cout<<endl;
// for(int i=0;i<n;i++){
//     for(int j=0;j<p;j++){
//         cout<<mularr[i][j]<<" ";
//     }
//     cout<<endl;
// }

// int n,m;
// cin>>n>>m;
// int arr[n][m]; 
// for(int i=0;i<n;i++){
//     for(int j=0;j<m;j++){
//         cin>>arr[i][j];
//     }
// }
// int key;cin>>key;
// int r=0,c=m-1;
// while (r<n && c>=0)
// {
//     if(arr[r][c]==key){
//         cout<<"element found";
//         break;
//     }
//     else if(arr[r][c]>key)c--;
//     else if(arr[r][c]<key)r++;
// }

return 0;
}
   