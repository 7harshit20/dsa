#include<iostream>
#include<vector>
using namespace std;

bool isright(string s){
        int sum=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' )sum++;
            else sum--;
            // cout<<sum<<endl;
            if(sum<0) return false;
        }
        return true;
    }
    void para(string s,int n,vector<string> &v){
        if(n==0) {
            v.push_back(s); 
            return;
        }
        int j=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==')')j=i;
        }
        string temp=s;
        // temp.append(j+1,')');
        for(int i=0;i<n;i++){
            s=temp;
            cout<<j<<endl;
            s.insert(j+1,")");
            if(isright(s)){
                 para(s,n-1,v);
            }
            else{
                j++;
                para(s,n-1,v);
            }
            j++;
        }
    }
    void generateParenthesis(int n) {
        string s="";
        for(int i=0;i<n;i++)s+="(";
        vector<string> v;
        para(s,n,v);
        for(auto ele:v)cout<<ele<<endl;
        
    }

int main(){
    generateParenthesis(3);
    // string s="()(())";
    // cout<<isright(s);
    
}