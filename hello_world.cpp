#include<iostream>
using namespace std;

int main(){

    cout<<"hello world\n";
    int a,b;
    cin>>a;
    cin>>b;
    cout<<a+b;
    

    int c,d,e,max,max2; 
    cin>>d>>e>>c;
    if(c>d){
        if(c>e)max=c;
        else max=e;
    }else{
        if(d>e)max=d;
        else max=e;
    }
    max2=c>d?c>e?c:e:d>e?d:e;
    cout<<"max is "<<max<<" "<<max2;

    
    return 0;
}