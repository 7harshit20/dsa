#include<iostream>
#include<stack>
using namespace std;

void reverseSentence(string s){
    stack<string> st;
    int i=0,j=0;
    for(i=0;i<s.length();i++){
        if(s[i+1]==' '|| i==s.length()-1){
            st.push(s.substr(j,i-j+1));
            j=i+2;
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
}

void insertAtBottom(stack<int> &st,int value){
    if(st.empty()){
        st.push(value);
        return;
    }
    int temp=st.top();
    st.pop();
    insertAtBottom(st,value);
    st.push(temp);
}

void reverseStack(stack<int> &st){
    if(st.empty())return;
    int value=st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,value);
}

int main(){
    string s="it's been a long day";
    reverseSentence(s);
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverseStack(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}
