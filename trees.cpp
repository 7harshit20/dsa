#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int num) {
        val=num;
        left=NULL;
        right=NULL;
    }
};

void preOrder(TreeNode* root) {
    if(root==nullptr)return;
    cout<<root->val<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void levelOrder(TreeNode* root, queue<TreeNode*>& add, vector<vector<int>>& sol) {
    int n=add.size();
    vector<int> ans;
    for(int i=0;i<n;i++) {
        if(add.front()->left)add.push(add.front()->left);
        if(add.front()->right)add.push(add.front()->right);
        ans.push_back(add.front()->val);
        add.pop();
    }
    sol.push_back(ans);
    if(!add.empty())levelOrder(add.front(), add, sol);
}

void levelOrder(TreeNode* root, vector<TreeNode*>& add, vector<int>& ans, vector<vector<int>>& sol, int i, vector<int>& level, int curr) {
    if(level[i]>curr) {
        sol.push_back(ans);
        ans.clear();
        curr++;
    }
    if(root->left) {
        ans.push_back(root->left->val);
        add.push_back(root->left);
        level.push_back(curr+1);
    }
    if(root->right) {
        ans.push_back(root->right->val);
        add.push_back(root->right);
        level.push_back(curr+1);
    }
    if(i+1<add.size())levelOrder(add[i+1], add, ans, sol, i+1, level, curr);
}

int maxDepth(TreeNode* root) {
    if(!root)return 0;
    return 1+max(maxDepth(root->left), maxDepth(root->right));
}

bool isBalanced(TreeNode* root) {
    // Remember I solved it by 4 method, first in O(n*2) is for this we iterate through every single node and find the height of its left and right subtrees, which is not efficient. In my second approach I created a new tree with the value of node as their length (The idea is that while finding height of a root, we find all the height of its subtrees, so the value is updated in only one iteration i.e., when finding height of the top root). In third I used same approach, just didn't created a new tree but simply updated the same given tree(which is easier). In the last approach I did not updated the value of node as length, but returned it instead (code is in leetcode).
    // O(N*2);
    // if(!root)return true;
    // if(abs(maxDepth(root->left)-maxDepth(root->right))>1)return false;
    // return (isBalanced(root->left) && isBalanced(root->right));
    // O(N)
    // if(root->val==0)return true;
    // if(abs(root->left->val-root->right->val)>1)return false;
    // return (isBalanced(root->left) && isBalanced(root->right));
    // O(N)
    if(!root)return true;
    if(abs(root->left->val-root->right->val)>1)return false;
    return (isBalanced(root->left) && isBalanced(root->right));

}
int heigthTree(TreeNode* root, TreeNode*& num) {
    num=new TreeNode(0);
    if(!root) return 0;
    num->val=1+max(heigthTree(root->left, num->left), heigthTree(root->right, num->right));
    return num->val;
}
int findHeight(TreeNode* root) {
    if(!root)return 0;
    root->val=1+max(findHeight(root->left), findHeight(root->right));
    return root->val;
}

int diameter(TreeNode* root, int& ans) {
    if(!root)return 0;
    int leftMax=diameter(root->left, ans);
    int rightMax=diameter(root->right, ans);
    ans=max(ans, leftMax+rightMax);
    return 1+max(leftMax, rightMax);
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if(!root)return false;
    if(!root->left && !root->right)return targetSum==root->val;
    if(!root->left)return hasPathSum(root->right, targetSum-root->val);
    if(!root->right)return hasPathSum(root->left, targetSum-root->val);
    return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
}

int mxPathSum(TreeNode* root, int& sum) {
    if(!root)return 0;
    int l=mxPathSum(root->left, sum);
    int r=mxPathSum(root->right, sum);
    sum=max(sum, max(l, 0)+max(r, 0)+root->val);
    return max(max(l, r), 0)+root->val;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(!p && !q)return true;
    if(p&&q) {
        if(p->val==q->val)return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    return false;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> sol;
    if(!root)return sol;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        int n=q.size();
        vector<int> ans(n, 0);
        for(int i=0;i<n;i++) {
            TreeNode* node=q.front();
            q.pop();
            if(sol.size()%2==1)ans[n-1-i]=node->val;
            else ans[i]=node->val;
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        sol.push_back(ans);
    }
    return sol;
}

void leftNodes(TreeNode* root, vector<int>& ans) {
    root=root->left;
    while(root) {
        if(root->left|| root->right)ans.push_back(root->val);
        if(root->left) root=root->left;
        else root=root->right;
    }
}
void rightNodes(TreeNode* root, vector<int>& ans) {
    vector<int> temp;
    root=root->right;
    while(root) {
        if(root->left || root->right)temp.push_back(root->val);
        if(root->right) root=root->right;
        else root=root->left;
    }
    int n=temp.size();
    for(int i=0;i<n;i++) ans.push_back(temp[n-1-i]);
}
void leafNodes(TreeNode* root, vector<int>& ans) {
    if(!root->left && !root->right)ans.push_back(root->val);
    if(root->left)leafNodes(root->left, ans);
    if(root->right)leafNodes(root->right, ans);
}
vector<int> boundaryTraversal(TreeNode* root) {
    vector<int> ans;
    if(!root)return ans;
    if(root->left || root->right)ans.push_back(root->val);
    leftNodes(root, ans);
    leafNodes(root, ans);
    rightNodes(root, ans);
    return ans;
}

void verticalTraversalSol(TreeNode* root, int x, int y, vector<vector<pair<int, int>>>& sol) {
    if(!root)return;
    sol[x].push_back({ root->val, y });
    verticalTraversalSol(root->left, x-1, y+1, sol);
    verticalTraversalSol(root->right, x+1, y+1, sol);
}
bool mycmp(pair<int, int> p1, pair<int, int> p2) {
    if(p1.second==p2.second)return p1.first<p2.first;
    return p1.second<p2.second;
}
vector<vector<int>> verticalTraversal(TreeNode* root) {
    int n=7;
    vector<vector<int>> finalSol;
    vector<vector<pair<int, int>>> sol(15, { {} });
    verticalTraversalSol(root, n, 0, sol);
    for(auto& ele: sol) {
        vector<int> temp;
        int size=ele.size();
        if(size==1)continue;
        sort(ele.begin(), ele.end(), mycmp);
        for(int i=1;i<size;i++) temp.push_back(ele[i].first);
        finalSol.push_back(temp);
    };
    return finalSol;
}


vector<int> rightSideView(TreeNode* root) {
    stack<TreeNode*> st;
    int level=1;
    vector<int> ans;
    while(root||!st.empty()) {
        if(!root) {
            root=st.top()->left;
            st.pop();
            level--;
        }
        st.push(root);
        if(!ans[level-1]) {
            ans[level-1]=root->val;
        }
        root=root->right;
        level++;
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(6);
    root->right->left=new TreeNode(5);
    root->right->right=new TreeNode(7);
    root->right->right->right=new TreeNode(8);
    root->right->right->right->left=new TreeNode(9);

    verticalTraversal(root);

    // vector<vector<int>> sol;
    // queue<TreeNode*> add;
    // add.push(root);
    // levelOrder(root, add, sol);

    // Iterative PreOrder
    // vector<int> ans;
    // stack<TreeNode*> st;
    // TreeNode* head=root;
    // do {
    //     if(!head) {
    //         head=st.top();
    //         st.pop();
    //     }
    //     ans.push_back(head->val);
    //     if(head->right)st.push(head->right);
    //     head=head->left;
    // } while(!st.empty() || head);
    // for(auto ele: ans)cout<<ele<<" ";

    // Iterative InOrder
    // vector<int> ans;
    // stack<TreeNode*> st;
    // while(!st.empty()||root) {
    //     if(!root) {
    //         root=st.top()->right;
    //         ans.push_back(st.top()->val);
    //         st.pop();
    //     }
    //     else{
    //         st.push(root);
    //         root=root->left;
    //     }
    // }
    // for(auto ele: ans)cout<<ele<<" ";

    // Iterative PostOrder
    // vector<int> ans;
    // stack<TreeNode*> st;
    // stack<int> check;
    // while(!st.empty()||root) {
    //     if(!root) {
    //         while(!check.empty() && check.top()==1) {
    //             ans.push_back(st.top()->val);
    //             st.pop();
    //             check.pop();
    //         }
    //         if(!st.empty()) {
    //             root=st.top()->right;
    //             check.top()=1;
    //         }
    //     }
    //     if(root) {
    //         st.push(root);
    //         check.push(0);
    //         root=root->left;
    //     }
    // }
    // for(auto ele: ans)cout<<ele<<" ";
    // vector<int> ans;
    // stack<TreeNode*> st;
    // TreeNode* pre;
    // TreeNode* ob=new TreeNode(0);
    // while(!st.empty()||root) {
    //     if(!root) {
    //         TreeNode* node=st.top();
    //         if(node==pre || node->left==pre) {
    //             root=node->right;
    //             pre= ob;
    //         }
    //         else {
    //             ans.push_back(node->val);
    //             pre=node;
    //             st.pop();
    //         }
    //     }
    //     else {
    //         st.push(root);
    //         pre=root;
    //         root=root->left;
    //     }
    // }
    // for(auto ele: ans)cout<<ele<<" ";

    // Pre,In,Post in one iteration
    // vector<int> pre, in, post;
    // stack<pair<TreeNode*, int>> st;
    // while(!st.empty()|| root) {
    //     if(!root) {
    //         auto& ele=st.top();
    //         if(ele.second==0) {
    //             in.push_back(ele.first->val);
    //             ele.second=1;
    //             root=ele.first->right;
    //         }
    //         else {
    //             post.push_back(ele.first->val);
    //             st.pop();
    //         }
    //     }
    //     else {
    //         pre.push_back(root->val);
    //         st.push({ root,0 });
    //         root=root->left;
    //     }
    // }
    // for(auto ele: pre)cout<<ele<<" ";
    // cout<<endl;
    // for(auto ele: in)cout<<ele<<" ";
    // cout<<endl;
    // for(auto ele: post)cout<<ele<<" ";
    // cout<<endl;

    // cout<<maxDepth(root)<<endl;
    // TreeNode* num=NULL;
    // heigthTree(root, num);

    // int ans=0;
    // diameter(root, ans);
    // cout<<ans;

    return 0;
}