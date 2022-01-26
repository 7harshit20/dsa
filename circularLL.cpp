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

void insertAtTail(node* &head,int value){
    node* n=new node(value);
    if(head==NULL){
        head=n;
        return;
    }
    if(head->next==NULL){
        head->next=n;
        n->next=head;
        return;
    }
    node* temp=head;
    while(temp->next!=head)temp=temp->next;
    temp->next=n;
    n->next=head;
}

void insertAtHead(node* &head,int value){
    node* n=new node(value);
    if(head==NULL){
        head=n;
        return;
    }
    if(head->next==NULL){
        n->next=head;
        head->next=n;
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=head)temp=temp->next;
    temp->next=n;
    n->next=head;
    head=n;
}

void deletion(node* &head,int pos){
    node* temp=head;
    if(pos==1){
        while(temp->next!=head)temp=temp->next;
        temp->next=head->next;
        temp=head;
        head=head->next;
        delete temp;
        return;
    }
    for(int i=1;i<pos-1;i++)temp=temp->next;
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

void display(node* head){
    node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=head);
    cout<<endl;
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtHead(head,0);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    deletion(head,1);
    deletion(head,5);
    display(head);
    return 0;
}