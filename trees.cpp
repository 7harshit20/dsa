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


void rightView(TreeNode* root, int level, vector<int>& ans) {
    if(!root)return;
    if(ans.size()==level)ans.push_back(root->val);
    rightView(root->right, level+1, ans);
    rightView(root->left, level+1, ans);
}
void bottomLeft(TreeNode* root, int level, pair<int, int>& ans) {
    if(!root)return;
    if(level>=ans.second)ans={ root->val,level };
    bottomLeft(root->right, level+1, ans);
    bottomLeft(root->left, level+1, ans);
}

void topSideView(TreeNode* root, int x, int y, vector<pair<int, int>>& ans) {
    if(!root)return;
    if(ans[x].first==0 || ans[x].second>y)ans[x]={ root->val,y };
    topSideView(root->right, x+1, y+1, ans);
    topSideView(root->left, x-1, y+1, ans);
}
vector<int> topView(TreeNode* root) {
    int n=1000000;
    vector<int> sol;
    vector<pair<int, int>> ans(n, { 0,0 });
    topSideView(root, n/2, 0, ans);
    for(int i=0;i<n;i++)if(ans[i].first!=0)sol.push_back(ans[i].first);
    return sol;
}

bool checkSym(TreeNode* root1, TreeNode* root2) {
    if(!root1 || !root2)return root1==root2;
    if(root1->val!=root2->val)return false;
    return checkSym(root1->left, root2->right) && checkSym(root1->right, root2->left);
}

void pathToLeaf(TreeNode* root, vector<int>& ans, vector<vector<int>>& sol) {
    if(!root)return;
    ans.push_back(root->val);
    if(!root->left && !root->right)sol.push_back(ans);
    pathToLeaf(root->left, ans, sol);
    pathToLeaf(root->right, ans, sol);
    ans.pop_back();
}

bool pathToNode(TreeNode* root, vector<int>& ans, TreeNode* target) {
    if(!root)return false;
    ans.push_back(root->val);
    if(root==target)return true;
    if(pathToNode(root->left, ans, target) || pathToNode(root->right, ans, target))return true;
    ans.pop_back();
    return false;
}

bool lca(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {
    if(ans||!root)return false;
    bool i=(root==p || root==q);
    bool l=lca(root->left, p, q, ans);
    bool r=lca(root->right, p, q, ans);
    if((l&&r)||(l&&i)||(r&&i))ans=root;
    return i||l||r;
}

int widthOfBinaryTree(TreeNode* root) {
    long long ans=1;
    queue<pair<TreeNode*, long long>> q;
    q.push({ root,1 });
    while(!q.empty()) {
        long long n=q.size(), s=0, e=0;
        for(int i=1;i<=n;i++) {
            TreeNode* node=q.front().first;
            long long x=q.front().second;
            if(i==1)s=x;
            if(i==n)e=x;
            if(node->left) {
                q.push({ node->left,x*2-1 });
            }
            if(node->right) {
                q.push({ node->right,x*2 });
            }
            q.pop();
        }
        cout<<e<<" "<<s<<endl;
        ans=max(ans, e-s+1);
    }
    return ans;
}


void kDown(TreeNode* root, int k, vector<int>& sol) {
    if(k<0)return;
    if(k==0) {
        sol.push_back(root->val);
        return;
    }
    if(root->left)kDown(root->left, k-1, sol);
    if(root->right)kDown(root->right, k-1, sol);
}

bool pathToNodeK(TreeNode* root, vector<TreeNode*>& ans, TreeNode* target) {
    if(!root)return false;
    ans.push_back(root);
    if(root==target || pathToNodeK(root->left, ans, target) || pathToNodeK(root->right, ans, target))return true;
    ans.pop_back();
    return false;
}

int timeDown(TreeNode* root) {
    int lt=0, rt=0;
    if(!root)return 0;
    if(root->left)lt=timeDown(root->left);
    if(root->right)rt=timeDown(root->right);
    return 1+max(lt, rt);
}

int totalNodes(TreeNode* root) {
    // Approach when all leaf nodes are not as far left as possible
    queue<TreeNode*> q;
    q.push(root);
    int found=0, num=0, level=1;
    while(!found) {
        int n=q.size();
        level++;
        for(int i=0;i<n;i++) {
            TreeNode* node=q.front();
            if(!node->left) {
                num++;
                found=1;
            }
            else q.push(node->left);
            if(!node->right) {
                num++;
                found=1;
            }
            else q.push(node->right);
        }
    }
    return pow(2, level)-num;
}

int countNodes(TreeNode* root) {
    if(!root)return 0;
    int lh=leftHeight(root->left);
    int rh=rightHeight(root->right);
    if(lh==rh)return pow(2, lh) - 1;
    return 1+countNodes(root->left)+countNodes(root->right);
}
int leftHeight(TreeNode* root) {
    if(!root)return 0;
    return 1+leftHeight(root->left);
}
int rightHeight(TreeNode* root) {
    if(!root)return 0;
    return 1+rightHeight(root->right);
}

TreeNode* preInTree(vector<int>& preorder, vector<int>& inorder, int& currRoot, int srootPos, int erootPos) {
    if(srootPos>erootPos)return nullptr;
    TreeNode* root=new TreeNode(preorder[currRoot]);
    int nrootPos=find(inorder.begin(), inorder.end(), preorder[currRoot]) - inorder.begin();
    currRoot++;
    root->left=preInTree(preorder, inorder, currRoot, srootPos, nrootPos-1);
    root->right=preInTree(preorder, inorder, currRoot, nrootPos+1, erootPos);
    return root;
}

TreeNode* postInTree(vector<int>& inorder, vector<int>& postorder, int& currRoot, int srootPos, int erootPos) {
    if(srootPos>erootPos)return nullptr;
    TreeNode* root=new TreeNode(postorder[currRoot]);
    int nrootPos=find(inorder.begin(), inorder.end(), postorder[currRoot])-inorder.begin();
    currRoot--;
    root->right=postInTree(inorder, postorder, currRoot, nrootPos+1, erootPos);
    root->left=postInTree(inorder, postorder, currRoot, srootPos, nrootPos-1);
    return root;
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
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->right=new TreeNode(7);
    root->left->right->left=new TreeNode(8);
    root->left->right->right=new TreeNode(9);

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

    // int k=2;
    // vector<TreeNode*> ans;
    // vector<int> sol;
    // pathToNodeK(root, ans, root->left);
    // int n=ans.size();
    // for(int i=0;i<n-1;i++) {
    //     if(ans[i]->left==ans[i+1] && ans[i]->right) kDown(ans[i]->right, k+i-n, sol);
    //     if(ans[i]->right==ans[i+1] && ans[i]->left) kDown(ans[i]->left, k+i-n, sol);
    // }
    // if(k<=n-1 && k!=0)sol.push_back(ans[n-1-k]->val);
    // kDown(ans[n-1], k, sol);
    // for(auto ele: sol) {
    //     cout<<ele<<" ";
    // }

    // TreeNode* target=root->left->right->left;
    // vector<TreeNode*> ans;
    // pathToNodeK(root, ans, target);
    // int n=ans.size(), sol=0;
    // for(int i=0;i<n-1;i++) {
    //     if(ans[i]->left==ans[i+1]) {
    //         sol=max(sol, n-1-i+timeDown(ans[i]->right));
    //     }
    //     if(ans[i]->right==ans[i+1]) {
    //         sol=max(sol, n-1-i+timeDown(ans[i]->left));
    //     }
    // }
    // sol=max(sol, timeDown(target)-0);
    // cout<<sol;


    return 0;
}