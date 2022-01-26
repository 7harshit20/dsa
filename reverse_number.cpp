#include <iostream>
using namespace std;

int main(){
   int n,a=0;
   cin>>n;
   while(n>0){
       a=10*a+n%10;
       n=n/10; 
   } 
   cout<<a; 
    return 0;
}