#include<iostream>
#include<stack>
using namespace std;
class queue{
    public:
    stack<int> st;
    void enqueue(int x){
        st.push(x);
    }
    void dequeue(){
        int ele=st.top();
        st.pop();
        if(st.empty())return;
        dequeue();
        st.push(ele);
    }
    int peek(){
        int ele=st.top();
        st.pop();
        if(st.empty()){
            st.push(ele);
            return ele;
        }
        int ans=peek();
        st.push(ele);
        return ans;
    }
    bool empty(){
        return st.empty();
    }
};
int main(){
    queue q;
    q.enqueue(1);
    q.enqueue(3);
    q.enqueue(5);
    while(!q.empty()){
        cout<<q.peek()<<" ";
        q.dequeue();
    }
    return 0;
}