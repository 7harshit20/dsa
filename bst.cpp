#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
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


TreeNode* searchBST(TreeNode* root, int val) {
    if(root->val==val)return root;
    if(root->val>val)return searchBST(root->left, val);
    return searchBST(root->right, val);
}

int findCeil(TreeNode* root, int x) {
    int ans=root->val;
    while(root && ans!=x) {
        if(root->val>=x) {
            ans=root->val;
            root=root->left;
        }
        else {
            root=root->right;
        }
    }
    if(ans<x)return -1;
    return ans;
}

int findFloor(TreeNode* root, int x) {
    int ans=root->val;
    while(root && ans!=x) {
        if(root->val<=x) {
            ans=root->val;
            root=root->right;
        }
        else {
            root=root->left;
        }
    }
    if(ans>x)return -1;
    return ans;
}

int minDiff(TreeNode* root, int x) {
    int ans=INT_MAX;
    while(root && ans!=0) {
        ans=min(abs(root->val-x), ans);
        if(root->val>=x) {
            root=root->left;
        }
        else {
            root=root->right;
        }
    }
    return ans;
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root)return new TreeNode(val);
    TreeNode* ret=root;
    while(root) {
        if(root->val<val) {
            if(!root->right) {
                root->right=new TreeNode(val);
                break;
            }
            root=root->right;
        }
        else {
            if(!root->left) {
                root->left=new TreeNode(val);
                break;
            }
            root=root->left;
        }
    }
    return ret;
}

TreeNode* helperDeleteNode(TreeNode* root) {
    if(!root->right)return root->left;
    TreeNode* rightChild=root->left;
    while(rightChild->left)rightChild=rightChild->left;
    rightChild->left=root->left;
    return root->right;

}
TreeNode* deleteNode(TreeNode*& root, int key) {
    if(!root)return nullptr;
    if(root->val==key)return helperDeleteNode(root);
    TreeNode* ret=root;
    while(root) {
        if(root->val>key) {
            if(root->left  && root->left->val==key) {
                root->left=helperDeleteNode(root->left);
                break;
            }
            root=root->left;
        }
        else {
            if(root->right && root->right->val==key) {
                root->right=helperDeleteNode(root->right);
                break;
            }
            root=root->right;
        }
    }
    return ret;
}

void kSmallest(TreeNode* root, int& k, int& ans) {
    if(ans!=-1)return;
    if(root->left)kSmallest(root->left, k, ans);
    k--;
    if(k==0)ans=root->val;
    else if(root->right)kSmallest(root->right, k, ans);
}

bool isValidBST(TreeNode* root) {
    bool l=true, r=true;
    if(root->left) {
        l=isValidBST(root->left);
        if(l) {
            TreeNode* temp=root->left;
            while(temp->right) {
                temp=temp->right;
            }
            l=root->val>temp->val;
        }
    }
    if(root->right) {
        r=isValidBST(root->right);
        if(r) {
            TreeNode* temp=root->right;
            while(temp->left) {
                temp=temp->left;
            }
            r=root->val<temp->val;
        }
    }
    return l&&r;
}
bool isBST(TreeNode* root, long mn=LONG_MIN, long mx=LONG_MAX) {
    if(!root)return true;
    if(root->val>=mx || root->val<=mn)return false;
    return isBST(root->left, mn, root->val) && isBST(root->right, root->val, mx);
}

TreeNode* lcaBST(TreeNode* root, TreeNode* p, TreeNode* q) {
    if((root->val-p->val)*(root->val-q->val)<=0)return root;
    if(root->val-p->val>0)return lcaBST(root->left, p, q);
    return lcaBST(root->right, p, q);
}

TreeNode* bstPreorder(vector<int>& preorder, int end, int curr) {
    if(curr>end)return nullptr;
    TreeNode* root=new TreeNode(preorder[curr]);
    int i=curr+1;
    while(i<=end && preorder[i]<=preorder[curr])i++;
    root->left=bstPreorder(preorder, i-1, curr+1);
    root->right=bstPreorder(preorder, end, i);
    return root;
}
TreeNode* BSTPreorder(vector<int>& preorder, int& i, int bound=INT_MAX) {
    if(i==preorder.size() || preorder[i]>bound)return nullptr;
    TreeNode* root=new TreeNode(preorder[i++]);
    root->left=BSTPreorder(preorder, i, root->val);
    root->right=BSTPreorder(preorder, i, bound);
    return root;
}

void inorderSuccessor(TreeNode* root, int val, int& ans) {
    if(!root)return;
    if(root->val<=val)inorderSuccessor(root->right, val, ans);
    else {
        ans=root->val;
        inorderSuccessor(root->left, val, ans);
    }
}

// void recoverBST(TreeNode* root, int lb=LONG_MIN, int ub=LONG_MAX) {
//     if(!root)return;
//     if(root->val>ub)swap(root->val);
//     recoverBST(root->left, lb, root->val);
//     recoverBST(root->left, root->val, ub);
// }

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    TreeNode* root=new TreeNode(10);
    root->left=new TreeNode(8);
    root->right=new TreeNode(17);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(9);
    root->right->left=new TreeNode(12);
    root->right->right=new TreeNode(25);
    root->left->right->left=new TreeNode(8);
    root->left->right->right=new TreeNode(9);
    root->left->right->right->left=new TreeNode(10);

    return 0;
}