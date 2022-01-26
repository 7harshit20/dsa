#include <iostream>
using namespace std;

int main()
{
    // char arr[100] = "hey there everyone";
    // int arr2[10]={1,3,34,3,234,43,234,5,23,23};
    // cout<<arr2<<endl;
    // cout<<arr<<endl;
    // int i = 0; 
    // while (arr[i] != '\0')
    // {
    //     cout << arr[i];
    //     i++;
    // }


    // palindrome
    // cout<<endl;
    // int n;cin>>n;
    // bool flag=true;
    // char p[n+1];cin>>p;
    // for(int i=0;i<n/2;i++){
    //     if(p[i]!=p[n-i-1])flag = false;
    // }
    // if(flag)cout<<"word is palindrome";
    // else cout<<"word is not palindrome";


    // largest word in sentence
    int n;cin>>n;cin.ignore();
    char arr[n+1];cin.getline(arr,n);cin.ignore();
    
    int mx=INT_MIN,j=0,s=0,e=0;
    cout<<arr[n-1];
    for(int i=0;i<n+1;i++){
        if(arr[i]==' ' || arr[i]=='\0'){
            if(mx<i-j){
                mx=i-j;
                s=j;
                e=i-1;
            }
            j=i+1;
        }
    }
    cout<<mx<<endl;
   for(int i=s;i<=e;i++){
       cout<<arr[i];
   }
    
    return 0;
}