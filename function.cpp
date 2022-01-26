#include<iostream>
using namespace std;
#include <cmath>
// void fibonacci(int n){
//  int a=0,b=1,c;
// for(int i=1;i<=n;i++){
//     c=a+b;
//     cout<<a<<" ";
//     a=b;
//     b=c;
// }
// }
// int main(){
// int n;
// cin>>n;
// fibonacci(n);
//     return 0;
// }

// int factorial(int n){
//     int fac=1;
//     for(int i=1;i<=n;i++){
//         fac *= i;
//     }
//     return fac;
// }
// int c(int n,int r){
//     return factorial(n)/(factorial(n-r)*factorial(r));
// }

void phytrip(int a,int b,int c){
    int mx,md,mn;
    mx=max(a,max(b,c));
    md=max(a,min(b,c));
    mn=min(a,min(b,c));
    if(mx*mx==md*md+mn*mn)cout<<"yes";
    else cout<<"not";
}

void binarytodecimal(int n){
    int dec=0,i=0;
    while(n>0){
        int digit = n%10;
        dec += pow(2,i)*digit;
        i++;
        n=n/10;
    }
    cout<<dec;
}

void octaltodecimal(int n){
    int dec=0,i=0;
    while(n>0){
        int digit = n%10;
        dec += pow(8,i)*digit;
        i++;
        n=n/10;
    }
    cout<<dec;
}

void decimaltobinary(int n){
    int digit=0,i=0;
    while(n!=0){
        digit += pow(10,i)*(n%2);
        n=n/2;
        i++;
    }
    cout<<digit;
}

void decimaltooctal(int n){
    int digit=0,i=0;
    while(n!=0){
        digit += pow(10,i)*(n%8);
        n=n/8;
        i++;
    }
    cout<<digit;
}

int main(){
    // int n;
    // cin>>n;
    // for(int i=0; i<n;i++){
    //     for (int j = 0; j < i; j++)
    //     {
    //         cout<<c(i,j)<<" ";
    //     }
    //   cout<<endl;  
    // }

    // int a,b,c;
    // cin>>a>>b>>c;
    // phytrip(a,b,c);

    int n;
    cin>>n;
    // binarytodecimal(n);
    //   octaltodecimal(n);
    // decimaltobinary(n);
    // decimaltooctal(n);

       return 0;
}