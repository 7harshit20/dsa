#include<iostream>
#include<queue>
using namespace std;
int qtoqw(queue<int> &q1,queue<int> &q2){
    int ele=q1.front();
    q1.pop();
    if(q1.empty()){
        return ele;
    }
    q2.push(ele);
    return qtoqw(q1,q2);
}
void qtoq(queue<int> &q1,queue<int> &q2){
    if(q1.empty()){
        return;
    }
    int ele=q1.front();
    q1.pop();
    q2.push(ele);
    qtoq(q1,q2);
}
class stack{
    public:
    queue<int> q1;
    queue<int> q2;
    void push(int x){
        q1.push(x);
    }
    void pop(){
        // int x=qtoqw(q1,q2);
        // qtoq(q2,q1);
        while(!q1.empty()){
            int x=q1.front();
            q1.pop();
            if(q1.empty())break;
            q2.push(x);
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    int top(){
        // qtoq(q1,q2);
        // int x=qtoqw(q2,q1);
        // q1.push(x);
        // return x;
        int x;
        while(!q1.empty()){
            x=q1.front();
            q1.pop();
            q2.push(x);
        }
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        return x;
    }
    bool empty(){
        return q1.empty();
    }
};

int main(){
    stack st;
    st.push(1);
    st.push(3);
    st.push(5);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }cout<<endl;
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}