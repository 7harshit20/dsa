#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* pre;
    node(int value){
        data=value;
        next=NULL;
        pre=NULL;
    }
};

void insertAtTail(node* &head,int value){
    node* n=new node(value);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL)temp=temp->next;
    temp->next=n;
    n->pre=temp;
}

void insertAtHead(node* &head,int value){
    node* n=new node(value);
    n->next=head;
    if(head!=NULL)head->pre=n;
    head=n;
}

void deletion(node* &head,int pos){
    node* temp=head;
    if(pos==1){
        head=temp->next;
        if(head!=NULL)head->pre=NULL;
        delete temp;
        return;
    }
    for(int i=1;i<pos-1;i++)temp=temp->next;
    node* todelete = temp->next;
    temp->next=temp->next->next;
    if(temp->next->next!=NULL)temp->next->next->pre=temp;
    delete todelete;
}

void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node* head=NULL;
    insertAtTail(head,10);
    insertAtTail(head,20);
    insertAtTail(head,30);
    insertAtHead(head,-10);
    insertAtHead(head,0);
    deletion(head,2);
    display(head);
    return 0;
}