#include<iostream>
#include<vector>
using namespace std;
void swap(int* a,int *b){
        int temp=*a;
        *a=*b;
        *b=temp;
    }
void reverse(vector<int> &v,int a,int b){
        for(int i=0;i<=(b-a)/2;i++){
            swap(&v[a+i],&v[b-i]);
        }
    }
vector<int> factorial(int N){
        // code here
        vector<int> v;
        v.push_back(1);
        for(int i=1;i<=N;i++){
            
            int carry=0;
            for(int j=v.size()-1;j>=0;j--){
                int dig =v[j];
                v[j]= ((dig*i)+ carry)%10;
                carry= (dig*i+ carry)/10;
                if(j==0 && carry!=0){
                    int k=v.size()-1;
                    while(carry!=0){
                        v.push_back(carry%10);
                        carry/=10;
                    }
                    reverse(v,0,k);
                    reverse(v,0,v.size()-1);
                }
            }
        }
        return v;
    }
vector<int> factorial2(int N){
        // code here
        vector<int> v;
        v.push_back(1);
        for(int i=1;i<=N;i++){
            
            int carry=0;
            int k=v.size();
            for(int j=0;j<k;j++){
                int dig =v[j];
                v[j]= ((dig*i)+ carry)%10;
                carry= (dig*i+ carry)/10;
                if(j==v.size()-1 && carry!=0){
                    while(carry!=0){
                        v.push_back(carry%10);
                        carry/=10;
                    }
                }
            }
        }
        reverse(v,0,v.size()-1);
        return v;
    }

int main(){
    int n;
    cin>>n;
    vector<int> v;
    v=factorial(n);
    for(auto ele:v)
    cout<<ele;
    return 0;
}