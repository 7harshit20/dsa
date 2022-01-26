#include<iostream>
#include<vector>
using namespace std;
        vector<int> v;
       vector <int> commonElements (int a[], int b[], int n1, int n2)
        {
            //code here.
            
            int i=0,j=0;
            while(i<n1 && j<n2){
                if(a[i]<b[i]){
                    i++;
                }
                else if(a[i]>b[i]){
                    j++;
                }
                else{
                    v.push_back(a[i]);
                    i++;
                }
            }
            return v;
            // finder(A,B,n1,n2,v);
            // int length =v.size();
            // int arr[length];
            // for(int i=0;i<length;i++){
            //     arr[i]=v[length-1-i];
            //     v.pop_back();
            // }
            // finder(arr,C,length,n3,v);
            return v;                 
        }
void finder(int a[],int b[],int n1,int n2,vector<int>&v){
            int i=0,j=0;
            while(i<n1 && j<n2){
                if(a[i]<b[i]){
                    i++;
                }
                else if(a[i]>b[i]){
                    j++;
                }
                else{
                    v.push_back(a[i]);
                    i++;
                }
            }
        }

int main(){
    // vector<int> v;
    int a[]={2,3,20,25,80};
    int b[]={1,4,15,20,80,300};
    commonElements(a,b,5,6);
    for(auto ele:v){
        cout<<ele<<" ";
    }
    return 0;
}