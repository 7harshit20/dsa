#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

string keypadArr[]={"","./","abc","def","ghi"};
vector<vector<int>> ans;
string reverse(string s,string ans){
    if(s.length()==0){
        return ans;
    }
    ans+=s[s.length()-1];
    s.erase(s.length()-1,1);
    return reverse(s,ans);
}
void replace_pi(string s){
    if(s.length()==0)return;
    if(s[0]=='p' && s[1]=='i'){
        cout<<"3.14";
        s.erase(0,2);
        replace_pi(s);
    }else{
        cout<<s[0];
        s.erase(0,1);
        replace_pi(s);
    }

}
void tower_of_hanoi(int n,char A,char B,char C){
    if(n==0)return;
    tower_of_hanoi(n-1,A,C,B);
    cout<<"move from "<<A<<" to "<<C<<endl;
    tower_of_hanoi(n-1,B,A,C);    
}
string remove_duplicate(string s, string ans){
    if(s.length()==0)return ans;
    if(s[0]!=ans[ans.length()-1])ans+=s[0];
    return remove_duplicate(s.substr(1),ans);
}
string x_to_end(string s){
    if(s.length()==0)return "";
    char ch=s[0];
    string ans = x_to_end(s.substr(1));
    if(ch=='x'){
        return ans+=ch;
    }
    return ch+ans;

}
void subseq(string s,string ans){
   if(s.length()==0){
       cout<<ans<<endl;
       return;
   }
   subseq(s.substr(1),ans);
   subseq(s.substr(1),s[0]+ans);
}
void subseqascii(string s,string ans){
   if(s.length()==0){
       cout<<ans<<endl;
       return;
   }
   int asc=s[0];
   subseqascii(s.substr(1),ans);
   subseqascii(s.substr(1),ans+s[0]);
   subseqascii(s.substr(1),ans+to_string(asc));
}
void keypad(string s, string ans){
    if(s.length()==0){ 
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<keypadArr[s[0]-'0'].length();i++){
        keypad(s.substr(1),ans+(keypadArr[s[0]-'0'])[i]);   
    }
}
// void phone(string s, string ans){
//     if(s.length()==0){
//         cout<<ans<<endl;
//         return;
//     }
//     for(int i=0;i<keypadArr[s[0]-'0'].length();i++){
//         string temp=keypadArr[s[0]-'0'];
//         ans+=temp[i];
//         phone(s.substr(1),ans);
//     }
// }
void permuteArr(vector<int> arr,int index){
    if(index==arr.size()){
        ans.push_back(arr);
        return;
    }
    for(int i=index;i<arr.size();i++){
        swap(arr[index],arr[i]);
        permuteArr(arr,index+1);
        swap(arr[index],arr[i]);
    }
}

int main(){

    // string s="";
    // cout<<reverse("harshit",s)<<endl;

    // replace_pi("harshitpi");

    // tower_of_hanoi(6,'A','B','C');

    // cout<<remove_duplicate("aaaddbbbcceff","")<<endl;

    // cout<<x_to_end("abxxjbssxxgdsxgx")<<endl;

    // subseq("abc","");
    // subseqascii("ABC","");   
    
    // keypad("234","");
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    permuteArr(v,0);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<v.size();j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}