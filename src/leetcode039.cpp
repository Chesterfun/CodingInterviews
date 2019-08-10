//
// Created by chester on 19-8-10.
// 组合总和：给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的数字可以无限制重复被选取。
// 说明：所有数字（包括 target）都是正整数。解集不能包含重复的组合。
// 示例：
// 输入: candidates = [2,3,5], target = 8,
// 所求解集为:[ [2,2,2,2], [2,3,3], [3,5] ]
//

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> item;
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        generate(0, candidates, item, result, target);

        return result;
    }

private:
    void generate(int start,vector<int> &nums, vector<int> &item, vector<vector<int>> &result, int gap) {
        if (gap == 0) {
            result.push_back(item);
            return;
        }
        for (int j = start; j < nums.size(); ++j) {
            if (nums[j] > gap)
                return;
            item.push_back(nums[j]);
            generate(j, nums, item, result, gap - nums[j]);
            item.pop_back();
        }
    }

};

int main() {
    vector<int> nums = {2,3,6,7};
    int target = 7;
    Solution solu;
    vector<vector<int>> result;
    result = solu.combinationSum(nums, target);
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