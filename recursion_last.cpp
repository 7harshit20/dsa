#include<iostream>
using namespace std;

int placing_tile(int n){
    if(n==1)return 1;
    if(n==0) return 0;
    int ways=0;
    ways+=placing_tile(n-1);
    ways+=placing_tile(n-2);
    return ways;
}
int friends_pair(int n){
    if(n==1 || n==0) return 1;
    return friends_pair(n-1)+ (n-1)*friends_pair(n-2);
}
int knapsack(int value[],int wt[],int n,int W){
    if(n==0 || W==0) return 0;
    if(W>wt[0])
    return max(knapsack(value+1,wt+1,n-1,W),
    value[0]+knapsack(value+1,wt+1,n-1,W-wt[0]));
    return knapsack(value+1,wt+1,n-1,W);
}

int main(){ 
    // cout<<placing_tile(4);
    // cout<<friends_pair(14);
    int value[]={100,50,150};
    int wt[]={10,20,30};
    cout<<knapsack(value,wt,3,50);
    return 0;
}