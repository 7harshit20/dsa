#include<iostream>
#include<stack>
using namespace std;

int postfix_evalution(string s){
    stack<int> st;
    int i=0;
    while(i<s.length()){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int b=st.top();
            st.pop();
            int a=st.top();
            st.pop();
            if(s[i]=='+')st.push(a+b);
            else if(s[i]=='-')st.push(a-b);
            else if(s[i]=='*')st.push(a*b);
            else if(s[i]=='/')st.push(a/b);
        }
        i++;
    }
    return st.top();
}

int prefix_evalution(string s){
    stack<int> st;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]>='0' && s[i]<='9'){
            st.push(s[i]-'0');
        }
        else{
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            if(s[i]=='+')st.push(a+b);
            else if(s[i]=='-')st.push(a-b);
            else if(s[i]=='*')st.push(a*b);
            else if(s[i]=='/')st.push(a/b);
        }
    }
    return st.top();
}

int prec(char c){
    if(c=='+' || c=='-')return 1;
    else if(c=='*' || c=='/')return 2;
    else if(c=='^') return 3;
    return -1;
}

string infix_to_postfix(string s){
    stack<char> st;
    string ans="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='(')st.push(s[i]);
        else if(s[i]==')'){
            while(st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }
        else if(s[i]-'a'>=0 && s[i]-'a'<26)ans+=s[i];
        else{
            if(st.empty() || st.top()=='(' || prec(s[i])> prec(st.top())){
                st.push(s[i]);
            }
            else{
                ans+=st.top();
                st.pop();
                st.push(s[i]);
            }
        }
    }
    while(!st.empty()){
                ans+=st.top();
                st.pop();
            }
    return ans;
}

string infix_to_prefix(string s){
    string ans="";
    stack<char> st;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]==')'){
            st.push(s[i]);
        }
        else if(s[i]-'a'>=0 && s[i]-'a'<26)ans=s[i]+ans;
        else if(s[i]=='('){
            while(st.top()!=')'){
                ans=st.top()+ans;
                st.pop();
            }
            st.pop();
        }
        else{
            if(st.empty()||st.top()==')'||prec(st.top())<=prec(s[i])){
                st.push(s[i]);
            }
            else{
                ans=st.top()+ans;
                st.pop();
                st.push(s[i]);
            }
        }
    }
    while(!st.empty()){
        ans=st.top()+ans;
        st.pop();
    }
    return ans;
}

int main(){
    cout<<postfix_evalution("46+2/5*7+")<<endl;
    cout<<prefix_evalution("-+7*45+20")<<endl;
    cout<<infix_to_postfix("(a-b/c)*(a/k-l)")<<endl;
    cout<<infix_to_prefix("(a-b/c)*(a/k-l)")<<endl;
    return 0;
}