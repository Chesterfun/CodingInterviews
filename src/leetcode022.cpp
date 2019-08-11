//
// Created by chester on 19-8-11.
// 括号生成。给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
//
// 例如，给出 n = 3，生成结果为：
// ["((()))", "(()())", "(())()", "()(())", "()()()"]
// 思路：递归

#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate("", n, n, result);
        return result;
    }

private:
    void generate(string item, int left, int right, vector<string> &result) {
        if (left == 0 && right == 0) {
            result.push_back(item);
            return;
        }
        if (left > 0) {
            generate(item + '(', left - 1, right, result);
        }
        if (left < right) {                                         //已经放的左括号的数量比右括号多的时候才可以放右括号
            generate(item + ')', left, right - 1, result);
        }
    }
};

int main() {
    vector<string> result;
    Solution solu;
    result = solu.generateParenthesis(3);
    for (int i = 0; i < result.size(); ++i) {
        printf("%s\n", result[i].c_str());
    }
    return 0;
}
