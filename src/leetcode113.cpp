//
// Created by chester on 19-8-15.
// 路径总和II:给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。 叶子节点是指没有子节点的节点。
//

#include <vector>
#include <stdio.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        int path_value = 0;
        traversal(root, path_value, sum, path, result);
        return result;
    }

private:
    void traversal(TreeNode *root, int &path_value, int sum, vector<int> &path, vector<vector<int>> &result) {
        if (!root) {
            return;
        }
        path_value += root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && path_value == sum)
            result.push_back(path);
        traversal(root->left, path_value, sum, path, result);
        traversal(root->right, path_value, sum, path, result);
        path_value -= root->val;       //遍历完了以当前节点为根节点的下面所有路径直到叶子节点，
        path.pop_back();               //则弹出当前节点寻找下一个遍历的路径有没有满足要求
    }
};

int main() {
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(8);
    TreeNode d(11);
    TreeNode e(13);
    TreeNode f(4);
    TreeNode g(7);
    TreeNode h(2);
    TreeNode x(5);
    TreeNode y(1);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    c.left = &e;
    c.right = &f;
    d.left = &g;
    d.right = &h;
    f.left = &x;
    f.right = &y;

    Solution solu;
    vector<vector<int>> result = solu.pathSum(&a, 22);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            printf("[%d]", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

