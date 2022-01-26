#include<iostream>
#include<stack>
#include<deque>
#include<queue>
#include<vector>
using namespace std;

// imp problem new algorithm
 vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n=nums.size();
        vector<int> ans;
        for(int i=0;i<k;i++){
            while(!q.empty() && nums[q.back()]<nums[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        ans.push_back(nums[q.front()]);
        for(int i=k;i<n;i++){
            if(q.front()==i-k){
                q.pop_front();
            }
            while(!q.empty() && nums[q.back()]<nums[i]){
                q.pop_back();
            }
            q.push_back(i);
            ans.push_back(nums[q.front()]);
        }
        return ans;
    }

bool redundantParanthesis(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*'|| s[i]=='/')st.push(s[i]);
        else if(s[i]==')'){
            if(st.top()=='(')return true;
            while(st.top()!='(')st.pop();
            st.pop();
        }
        else continue;
    }
    return false; 
}

vector<int> stockSpan(vector<int> arr,int n){
    vector<int> ans;
        for(int i=0;i<n;i++){
          int j=i-1;
          int sum=1;
          while(j>=0 && arr[j]<=arr[i]){
              sum+=ans[j];
              j-=ans[j];
          }
          ans.push_back(sum);
        }
    return ans;
}

int main(){

    // string s="((a*b)+d*((e+f)))";
    // cout<<redundantParanthesis(s)<<endl;

    return 0;
}