//
// Created by chester on 19-8-9.
// 求数组子集II (数组子集第一题见leetcode078)
// 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。解集不能包含重复的子集。
// 示例：nums = [2,1,2,2]
// 结果为[[], [1], [1,2], [1,2,2], [1,2,2,2], [2], [2,2], [2,2,2]]
// 注意: [2,1,2]与[1,2,2]是重复的集合!
// 思路：在第一题的基础上，去掉重复的集合。
// 先对数组排序， 则取出来的子集全是顺序相同的形式， 即不存在[2,1,2],[1,2,2]的情况， 再考虑去掉相同的多个[1,2,2]情况，可利用set的find方法去重

#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        set<vector<int>> res_set;
        vector<int> item;
        sort(nums.begin(),nums.end());
        result.push_back(item);
        generate(0, nums, item, result, res_set);
        return result;
    }

private:
    void generate(int i, vector<int> &nums, vector<int> item, vector<vector<int>> &result, set<vector<int>> &res_ret) {
        if (i >= nums.size())
            return;
        item.push_back(nums[i]);
        if (res_ret.find(item) == res_ret.end()) {
            result.push_back(item);
            res_ret.insert(item);
        }
        generate(i+1, nums, item, result, res_ret);
        item.pop_back();
        generate(i+1, nums, item, result, res_ret);
    }
};

int main() {
    vector<int> nums = {1,2,2};
    Solution solu;
    vector<vector<int>> result;
    result = solu.subsetsWithDup(nums);
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