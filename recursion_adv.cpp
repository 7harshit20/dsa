#include<iostream>
#include<string>
using namespace std;

// recursion op in the chat

void permutation(string s, string answer){
    if(s.length()==0){
        cout<<answer<<endl;
        return;
    }    
    for(int i=0;i<s.length();i++){
        string rem= s.substr(0,i)+s.substr(i+1);
        permutation(rem,answer+s[i]);
    }
}
int total_path(int pos){
    if(pos<0)return 0;
    if(pos==0|| pos==1)return 1;
    return (total_path(pos-1))+(total_path(pos-2))+(total_path(pos-3))+(total_path(pos-4))+(total_path(pos-5))+(total_path(pos-6));
}
int count_path(int s, int e){

   if(s==e){
       return 1;
   }
   if(s>e){
       return 0;
   }
   int count =0;
   for(int i=1;i<=6;i++){
       count+=count_path(s+i,e);
   }
   return count;
}
int maze_path(int i, int j){
    if(i<0 || j<0)return 0;
    if(i==0 || j==0)return 1;
    return maze_path(i-1,j)+ maze_path(i,j-1);
}

int main(){

    string s="";
    permutation("har",s);


    // cout<<total_path(25)<<endl;
    // cout<<count_path(0,25)<<endl;

    // cout<<maze_path(5,5)<<endl;
    return 0;
}