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
    // node np(value);
    // node* n=&np;
    // why this does not work??
    node* n=new node(value);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void insertAtHead(node* &head,int value){
    node* n=new node(value);
    n->next=head;
    head=n;
}

void deletion(node* &head,int value){
    node* temp=head;
    if(head==NULL)return;
    if(temp->data==value){
        head=temp->next;
        delete temp;
        return;
    }
    while(temp->next->data!=value)temp=temp->next;
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

void reverseList(node* &head){
    node* pre=NULL;
    node* after;
    while(after!=NULL){
        after=head->next; 
        head->next=pre;
        pre=head;
        head=after;
    }
    head=pre;
}

node* reverseUsingRecursion(node* &head){
    if(head->next==NULL || head==NULL)return head;
    node* rhead=reverseUsingRecursion(head->next);
    head->next->next=head;
    head->next=NULL;
    return rhead;
}

bool search(node* &head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key)return true;
        temp=temp->next;
    }
    return false;
}

void display(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void reverseKNodes(node* &head,int k){
    if(head==NULL)return;
    node* pre=NULL;
    node* after;
    node* curr=head;
    int i=0;
    while(after!=NULL && i!=k){
        after=curr->next;
        curr->next=pre;
        pre=curr;
        curr=after;
        i++;
    }
    reverseKNodes(curr,k);
    head->next=curr;
    head=pre;
}

void makecycle(node* head, int pos){
    node* temp=head;
    node* startNode;
    int i=1;
    while(temp->next!=NULL){
        if(i==pos)startNode=temp;
        temp=temp->next;
        i++; 
    }
    temp->next=startNode; 
}

bool cyclepre(node* &head){
    node* slowptr=head;
    node* fastptr=head;
    while(fastptr!=NULL && fastptr->next!=NULL){
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
        if(slowptr==fastptr) return true;
    }
    return false;
}

void removecycle(node *&head){
    node* slowptr=head;
    node* fastptr=head;
    while(fastptr!=NULL && fastptr->next!=NULL){
        slowptr=slowptr->next;
        fastptr=fastptr->next->next;
        if(slowptr==fastptr){
            slowptr=head;
            break;
        }
    }
    while(slowptr->next!=fastptr->next){
        slowptr=slowptr->next;
        fastptr=fastptr->next;
    }
    fastptr->next=NULL;
}

void appendK(node* &head, int k){
    node* temp1=head;
    node* temp2=head;
    int i=1;
    while(temp1->next!=NULL){
        temp1=temp1->next;
        i++;
    }
    temp1->next=head;    
    while(i-k!=1){
        temp2=temp2->next;
        i--;
    }
    head=temp2->next;
    temp2->next=NULL;
}

void makeIntersection(node* head1,node* head2,int pos){
    node* temp=head2;
    while(temp->next!=NULL)temp=temp->next;
    node* temp2=head1;
    for(int i=1;i<pos;i++)temp2=temp2->next;
    temp->next=temp2;
}

int detectIntersection(node* head1,node* head2){
    node* temp=head1;
    while(temp->next!=NULL)temp=temp->next;
    temp->next=head2;
    if(cyclepre(head1)){
        node* slowptr=head1;
        node* fastptr=head1;
        while(fastptr!=NULL && fastptr->next!=NULL){
            slowptr=slowptr->next;
            fastptr=fastptr->next->next;
            if(slowptr==fastptr){
                slowptr=head1;
                break;
            }
        }
        while(slowptr->next!=fastptr->next){
            slowptr=slowptr->next;
            fastptr=fastptr->next;
        }
    return fastptr->next->data;
    }
    return -1;
}

node* mergeSortedLL(node* head1, node* head2){
    node* dummynode=new node(-1);
    node* ptr1=head1;
    node* ptr2=head2;
    node* ptr3=dummynode;
    while(ptr2!=NULL && ptr1!=NULL){
        if(ptr1->data<ptr2->data){
            ptr3->next=ptr1;
            ptr1=ptr1->next;    
        }
        else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    if(ptr1!=NULL){
        ptr3->next=ptr1;
    }
    if(ptr2!=NULL){
        ptr3->next=ptr2;
    }
    return dummynode->next;
}

node* mergeRecursion(node* head1, node* head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;        
    }
    node* result;
    if(head1->next<head2->next){
        result=head1;
        result->next=mergeRecursion(head1->next,head2);
    }
    else{
        result=head2;
        result->next=mergeRecursion(head1,head2->next);
    }
    return result;
}

void evenAfterOdd(node* head){
    node* temp=head->next;
    node* oddptr=head;
    node* evenptr=head->next;
    while(oddptr->next!=NULL && evenptr->next!=NULL){
        oddptr->next=oddptr->next->next;
        evenptr->next=evenptr->next->next;
        oddptr=oddptr->next;
        evenptr=evenptr->next;
    }
    oddptr->next=temp;
}

int main(){
    node* head=NULL;
    insertAtTail(head,21);
    insertAtTail(head,23);
    insertAtTail(head,25);
    insertAtTail(head,27);
    insertAtTail(head,29);
    insertAtHead(head,19);
    insertAtHead(head,17);
    cout<<search(head,15)<<endl;
    deletion(head,17);
    reverseList(head);
    head=reverseUsingRecursion(head);
    // display(head);
    // reverseKNodes(head,2);
    // display(head);
    makecycle(head,5);
    cout<<cyclepre(head)<<endl;
    removecycle(head);
    cout<<cyclepre(head)<<endl;
    // appendK(head,4);
    display(head);
    node* head2=NULL;
    insertAtTail(head2,22);
    insertAtTail(head2,24);
    insertAtTail(head2,26);
    insertAtTail(head2,28);
    insertAtTail(head2,30);
    // makeIntersection(head,head2,3);
    display(head2);
    // cout<<detectIntersection(head,head2)<<endl;
    node* head3=mergeSortedLL(head,head2);
    display(head3);
    evenAfterOdd(head3);
    display(head3);
    return 0;
}