//
// Created by chester on 19-8-1.
// 移掉K位数字。给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。
// 注意:
// num 的长度小于 10002 且 ≥ k。
// num 不会包含任何前导零。
// 示例：
// 输入: num = "1432219", k = 3
// 输出: "1219"
// 解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。
//
// 思路：贪心算法。
// 用一个vector存储最终结果的字符串，依次进来一个元素，当第i+1个元素比第i个元素小时，删除第i个元素形成的数字肯定比删除第i+1个元素形成的数字要大，所以删除第i个元素
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> S;
        string result = "";
        for (int i = 0; i < num.length(); ++i) {
            while (S.size() != 0 && S.back() > num[i] && k > 0) {       //当vector不为空且尾部元素比当前元素大，并且仍然可以删除数字时
                S.pop_back();                                           //删除尾部元素
                k--;
            }
            if (num[i] != '0' || S.size() != 0) {
                S.push_back(num[i]);
            }
        }

        while (S.size() != 0 && k > 0) {                         //当遍历完了数字串但还没有删除完时（例如“16145(k=3)”这样的数字串,遍历之后只会删除‘6’）
            S.pop_back();                                        //说明后面没有执行删除操作的元素是递增的，直接从末尾接着删除即可
            k--;                                                 //更新还需删除的数字个数k
        }
        for (int i = 0; i < S.size(); ++i) {                    //将结果存入result
            result.append(1,S[i]);
        }
        if (result == "") {                                     //result为空即为“0”
            result = "0";
        }
        return result;
    }
};

int main() {
    string num = "1432219";
    int k = 3;

    Solution solu;
    cout << num << endl;
    cout << solu.removeKdigits(num, k) << endl;
    return 0;
}