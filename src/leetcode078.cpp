//
// Created by chester on 19-8-9.
// 求数组子集：给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。解集不能包含重复的子集。
// 示例
// 输入：nums = [1,2,3]
// 输出：[ [3], [1], [2], [1,2,3], [1,3], [2,3], [1,2], [] ]
// 思路：
// 方法1回溯法 ，递归
// 方法2位运算法：若一个集合有三个元素 A, B, C ,则3个元素有2^3 = 8种 组成集合的 方式 ,用0-7 表示 这些 集合 。
// A元素为001 = 1;B元素为010 = 2;C元素为100 = 4
// 如构造某一集合,即使用A,B,C对应的三个整数与该集合对应的整数做&运算,当为真时,将该元素push进入集合。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {                                    //方法1：回溯法
        vector<int> item;                       //回溯时，产生各个子集的数组
        vector<vector<int>> result;             //储存最终结果的数组
        result.push_back(item);                 //先将空集push入result
        generate(0, nums, item, result);        //计算各个子集
        return result;
    }

    vector<vector<int>> subsets1(vector<int>& nums) {                                   //方法2：位运算法
        int n = 1 << nums.size();                                                       //有nums.size()种集合的方式
        vector<vector<int>> result;
        for (int i = 0; i < n; ++i) {                                                   //遍历n种情况
            vector<int> item;
            for (int j = 0; j < nums.size(); ++j) {                                     //分别考虑nums中每个元素是否选择
                if (i & (1<<j)) {                                                       //i代表从0至2^n -1这2^n个集合
                    item.push_back(nums[j]);
                }
            }
            result.push_back(item);
        }
        return result;
    }

private:
    void generate(int i, vector<int> &nums, vector<int> &item, vector<vector<int>> &result) {
        if (i >= nums.size())                   //递归结束条件
            return;
        item.push_back(nums[i]);
        result.push_back(item);                 //将当前生成的子集添加进入result
        generate(i+1, nums, item, result);      //第一次递归调用
        item.pop_back();
        generate(i+1, nums, item, result);      //回溯不选择nums[i]元素的情况，进行递归调用
    }
};

int main() {
    vector<int> nums = {1,2,3};
    Solution solu;
    vector<vector<int>> result;
    result = solu.subsets1(nums);
    for (int i = 0; i < result.size(); ++i) {
        if (result[i].size() == 0) {
            printf("[]");
            }
        for (int j = 0; j < result[i].size(); ++j) {
            printf("[%d]", result[i][j]);
        }
        printf("\n");
    }
    return 0;

}