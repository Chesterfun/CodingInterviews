//
// Created by shmil on 2019/8/31.
// 二叉树转链表：给定一个二叉树，就地转换为单链表，单链表中节点顺序为二叉树前序遍历顺序。就地转换意思是不能额外申请空间储存链表
//

#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

class Solution {                                            //方法一：递归
public:
    void flatten(TreeNode *root) {
        TreeNode *last = NULL;
        preoder(root, last);
    }

private:
    void preoder(TreeNode *node, TreeNode *&last) {
        if (!node)
            return;
        if (!node->left && !node->right) {
            last = node;
            return;
        }
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        TreeNode *left_last = NULL;
        TreeNode *right_last = NULL;
        if (left) {
            preoder(left, left_last);
            node->left = NULL;
            node->right = left;
            last = left_last;
        }
        if (right) {
            preoder(right, right_last);
            if (left_last) {
                left_last->right = right;
            }
            last = right_last;
        }
    }
};

class SolutionNew {                                 //方法二：利用栈
public:
    void flatten(TreeNode *root) {
        if (!root) {
            return;
        }
        stack<TreeNode *> S;
        S.push(root);
        while (!S.empty()) {
            TreeNode *p = S.top();
            S.pop();
            if (p->right) {
                S.push(p->right);
            }
            if (p->left) {
                S.push(p->left);
            }
            p->left = NULL;
            if (!S.empty()) {
                p->right = S.top();
            }
        }
    }
};

int main() {
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);
    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    SolutionNew solve;
    solve.flatten(&a);
    TreeNode *head = &a;
    while (head) {
        if (head->left) {
            cout << "ERROR!" << endl;
        }
        printf("[%d]", head->val);
        head = head->right;
    }
    printf("\n");
    return 0;
}