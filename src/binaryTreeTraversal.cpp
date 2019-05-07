//二叉树的遍历，先序遍历、中序遍历

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    };

class Solution {
    vector<int> preorderTraversal_Recur(TreeNode* root)
    {
        vector<int> result;
        if(root)
        {
            result.push_back(root->val);
            preorderTraversal_Recur(root->left);
            preorderTraversal_Recur(root->right);
        }
        return result;
    }

    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> result;
        stack<TreeNode*> S;
        if (root) S.push(root);

        while (!S.empty()){
            const TreeNode *p = S.top();
            S.pop();
            result.push_back(p->val);
            if (p->right != nullptr) S.push(p->right);
            if (p->left != nullptr) S.push(p->left);
        }
        return result;

    }

    vector<int> inorderTraversal(TreeNode * root)
    {
        vector<int> res;
        stack<TreeNode *> S;
        TreeNode * pt = root;
        while (true)
        {
            goAlongLeftBranch(TreeNode* pt, stack<TreeNode *> & S);
            if(S.empty()) break;

            pt = S.top();
            S.pop();
            res.push_back(pt->val);
            pt = pt->right;

        }
        return res;
    }

private:
    void goAlongLeftBranch(TreeNode* tp, stack<TreeNode *> & S)
    {
        while(tp)
        {
            S.push(tp->val);
            tp = tp->left;
        }
    }
};


