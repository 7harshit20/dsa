#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string toUppercase(string str){
    for(int i=0;i<str.length();i++){
        if(str[i]>'a'){
            str[i]-=32;
        }
    }
    return str;
}
int gcd(int a,int b){
    while (b!=0)
    {
        int rem=a%b;
        a=b;
        b=rem;
    }
    return a;
}

int main(){

    // string str="sdIOdSgesl";
    // str=toUppercase(str);
    // transform(str.begin(),str.end(),str.begin(),::tolower);
    // cout<<str<<endl;

    // string s="127759036";
    // sort(s.begin(),s.end(),greater<int>());
    // cout<<s<<endl;

    // string s="avfofffef";
    // int arr[26];
    // for(int i=0;i<26;i++){
    //     arr[i]=0;
    // }
    // for(int i=0;i<s.length();i++){
    //     arr[s[i]-'a']++;
    // }
    // int max=0;
    // for(int i=0;i<26;i++){
    //     if(arr[i]>arr[max])max=i;
    // }
    // cout<<"frequency "<<arr[max]<<endl;
    // cout<<"alpha "<<(char)(max+97)<<endl;

    cout<<gcd(2,36)<<endl;
 }