#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        bool arr[8][8]={false};
        for(int i=0;i<queens.size();i++){
        int a=queens[i][0];
            int b=queens[i][1];
            arr[a][b]=true;
        }
        int i=king[0],j=king[1];
        for(int i=0;i<queens.size();i++){
            queens.pop_back();
        }
        vector<int> pos;
        while(j<8){
            if(arr[i][j]){
                pos[0]=i;
                pos[1]=j;
                queens.push_back(pos);
                break;
            }
            j++;
        }
        i=king[0],j=king[1];
        while(j>=0){
            if(arr[i][j]){
                pos[0]=i;
                pos[1]=j;
                queens.push_back(pos);
                break;
            }
            j--;
        }
        i=king[0],j=king[1];
        while(i<8){
            if(arr[i][j]){
                pos[0]=i;
                pos[1]=j;
                queens.push_back(pos);
                break;
            }
            i++;
        }
        i=king[0],j=king[1];
        while(i>=0){
            if(arr[i][j]){
                pos[0]=i;
                pos[1]=j;
                queens.push_back(pos);
                break;
            }
            i--;
        }
    return queens;
}

int main(){
    
    return 0;
}