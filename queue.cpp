#include<iostream>
using namespace std;
#define n 20
class queue{
    int* arr;
    public:
    int front,back;

    queue(){
        arr=new int[n];
        front=-1;
        back=-1;
    }

    void enqueue(int value){
        if(front==-1)front++;
        if(back==n-1){
            cout<<"queue overflow"<<endl;
            return;
        }
        back++;
        arr[back]=value;
    }
    void dequeue(){
        if(front==-1 || front>back){
            cout<<"empty queue"<<endl;
            return;
        }
        front++;
    }
    int peek(){
        if(front==-1 || front>back){
            cout<<"empty queue"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool empty(){
        if(front==-1 || front>back)return true;
        return false;
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