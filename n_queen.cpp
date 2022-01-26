#include<iostream>
using namespace std;

bool issafe(int x,int y, int n,int **sarr){
    int i,j;
    for(i=0;i<x;i++){
        if(sarr[i][y]==1){
            return false;
        }
    }
    // for(i=x-1,j=y-1;i>=0 && j>=0;i--,j--){
        // if(sarr[i][j]==1){
        //     return false;
        // }
    // }
    // for(i=x-1,j=y+1;i<x && i>=0,j<n;i--,j++){
    //     if(sarr[i][j]==1){
    //         return false;
    //     }
    // }
    i=x;j=y;
    while(i>=0 && j>=0){
            if(sarr[i][j]==1){
            return false;
        }
        i--; j--;
    }
    i=x;j=y;
    while(i>=0 && j<n){
            if(sarr[i][j]==1){
            return false;
        }
        i--; j++;
    }
    return true;
}
bool nqueen(int x,int y, int n,int** sarr){
    if(y==n) return false;
    if(x==n) return true;
    if(issafe(x,y,n,sarr)){
        sarr[x][y]=1;
        if(nqueen(x+1,0,n,sarr)) return true;
        sarr[x][y]=0;
        return nqueen(x,y+1,n,sarr);
    }
    else return nqueen(x,y+1,n,sarr);
}
bool nqueen_using_loop(int x, int n, int** sarr ){
    if(x==n) return true;
    for(int i=0;i<n;i++){
        if(issafe(x,i,n,sarr)){
            sarr[x][i]=1;
            if(nqueen_using_loop(x+1,n,sarr)){
            return true;
            }
            sarr[x][i]=0;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    // int** arr=new int *[n];
    
    // for(int i=0;i<n;i++){
    //     arr[i]=new int[n];
    //     for(int j=0;j<n;j++){
    //         arr[i][j]=0;
    //     }
    // }
    int** sarr=new int *[n];
    for(int i=0;i<n;i++){
        sarr[i]=new int[n];
        for(int j=0;j<n;j++){
            sarr[i][j]=0;
        }
    }
    // cout<<endl;
    if(nqueen(0,0,n,sarr)){
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<sarr[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}
}