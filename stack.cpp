#include<iostream>
using namespace std;
#define n 100
class stack{
    int* arr;
    int top;
    public:
    stack(){
        arr=new int[n];
        top=-1;
    }
    
    void push(int value){
        if(top==n-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        arr[top+1]=value;
        top++;
    }

    void pop(){
        if(top==-1){
            cout<<"empty stack"<<endl;
            return;
        }
        top--;
    }

    int Top(){
        if(top==-1){
            cout<<"empty stack"<<endl;
            return -1;
        }
        return arr[top];
    }

    bool empty(){
        return top==-1;
    }

};

int main(){
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.Top()<<endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout<<st.empty()<<endl;
    return 0;
}