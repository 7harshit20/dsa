#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int value){
        data=value;
        next=NULL;
    }
};
class queue{
    public:
    node* head;
    node* tail;
    queue(){
        head=NULL;
        tail=NULL;
    }
    void push(int x){
        node* n=new node(x);
        if(head==NULL){
            head=n;
            tail=n;
            return;
        }
        tail->next=n;
        tail=n;
    }
    void pop(){
        if(head==NULL){
            cout<<"empty queue"<<endl;
            return;
        }
        node* temp=head;
        head=head->next;
        if(tail==temp)tail=NULL;
        delete temp;
    }
    int peek(){
        if(head==NULL){
            cout<<"empty quueue"<<endl;
            return -1;
        }
        return head->data;
    }
    bool empty(){
        if(head==NULL)return true;
        return false;
    }
};
int main(){
    queue q;
    q.push(1);
    q.push(3);
    q.pop();
    q.push(5);
    while(!q.empty()){
        cout<<q.peek()<<" ";
        q.pop();
    }
    return 0;
}