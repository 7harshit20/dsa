#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void swap(int* a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
    }

void swapchar(char* a, char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
    }

int main(){

    // string str;
    // cin>>str;
    // cout<<str;
    // getline(cin,str);
    // cout<<str;


    // string str1="water";
    // string str2="melon";
    // str1.append(str2);
    // str2=str1+str2;
    // cout<<str1<<endl;
    // cout<<str2<<endl;
    // cout<<str1[2]<<" "<<str2[3]<<endl;

    string str1="water";
    string str2="((((";
    // cout<<str2.compare(str1)<<endl;
    // // str1.clear();
    // cout<<str1.empty()<<endl;
    // str2.erase(3,1);

    // cout<<str2[0]*str2[1]<<endl;

    // cout<<str2<<endl;
    str2.insert(1,"e");
    str2+=str1[2];
    cout<<str2<<endl;
    // cout<<str2.length()<<endl;
    string str3= str1.substr(1,2);
    cout<<str3<<endl;

    // string s1="7482";
    // int x=stoi(s1);
    // cout<<x+3<<endl;
    // cout<<to_string(x)+"3"<<endl;


    // sorting string
    // string s="harshit";
    // int arr[s.length()];
    // for(int i=0;i<s.length();i++){
    //     arr[i]=(int)s[i];
    // }
    // int n=s.length();
    //  for(int i=0;i<n;i++){
    //     for(int j=0;j<n-1-i;j++){
    //         if(arr[j]>arr[j+1]){
    //             swap(&arr[j],&arr[j+1]);
    //             swapchar(&s[j],&s[j+1]);
    //         }
    //     }
    // }
    // cout<<s<<endl;
    // sort(s.begin(),s.end());
    // cout<<s<<endl;
    return 0;
}