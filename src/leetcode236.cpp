//
// Created by chester on 19-8-17.
// 二叉树的最近公共祖先
// 思路：先找到根节点到两个所给节点的路径，然后遍历两个路径找到最后一个相同的节点即是最近公共祖先节点

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode *> path;
        vector<TreeNode *> path_p;
        vector<TreeNode *> path_q;
        int finish = 0;
        traversal(root, p, path, path_p, finish);
        path.clear();
        finish = 0;
        traversal(root, q, path, path_q, finish);
        int path_len = path_p.size() < path_q.size()? path_p.size():path_q.size();
        TreeNode *result = 0;
        for (int i = 0; i < path_len; ++i) {
            if (path_p[i] == path_q[i])
                result = path_p[i];
        }
        return result;
    }

private:
    void traversal(TreeNode *node, TreeNode *search, vector<TreeNode *> &path, vector<TreeNode *> &result, int &finish) {
        if (!node || finish == 1) {
            return;
        }
        path.push_back(node);
        if (node == search) {
            result = path;
            finish = 1;
        }
        traversal(node->left, search, path, result, finish);
        traversal(node->right, search, path, result, finish);
        path.pop_back();
    }
};

int main() {
    TreeNode a(3);
    TreeNode b(5);
    TreeNode c(1);
    TreeNode d(6);
    TreeNode e(2);
    TreeNode f(0);
    TreeNode g(8);
    TreeNode h(7);
    TreeNode i(4);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.left = &f;
    c.right = &g;
    e.left = &h;
    e.right = &i;
    Solution solu;
    TreeNode *reslut = solu.lowestCommonAncestor(&a, &b, &f);
    printf("b&f lowest common ancestor = %d\n", reslut->val);
    reslut = solu.lowestCommonAncestor(&a, &d, &i);
    printf("d&i lowest common ancestor = %d\n", reslut->val);
    return 0;
}