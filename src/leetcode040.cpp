//
// Created by chester on 19-8-10.
// 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
// candidates 中的每个数字在每个组合中只能使用一次。
// 说明：所有数字（包括目标数）都是正整数。 解集不能包含重复的组合。 
// 示例：
// 输入: candidates = [2,5,2,1,2], target = 5,
// 所求解集为:[ [1,2,2], [5] ]
// 思路：在leetcode090求数组所有子集的基础上，留下和为target的子集，注意由于所有数字都是正数，当某个数子大于target时，可以不用考虑，即进行剪枝，否则会超时。

#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> item;
        vector<vector<int>> result;
        set<vector<int>> res_set;
        sort(candidates.begin(), candidates.end());
        generate(0, candidates, item, result, res_set, 0, target);
        return result;
    }

private:
    void generate(int i, vector<int> &candidates, vector<int> &item,
            vector<vector<int>> &result, set<vector<int>> &res_set, int sum, int target) {
        if (i >= candidates.size() || sum > target)                     //sum为当前子集item中的元素和
            return;
        sum += candidates[i];
        item.push_back(candidates[i]);
        if (sum == target && res_set.find(item) == res_set.end()) {
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i+1, candidates, item, result, res_set, sum, target);
        sum -= candidates[i];
        item.pop_back();
        generate(i+1, candidates, item, result, res_set, sum, target);
    }
};

int main() {
    vector<int> candidate = {2,5,2,1,2};
    vector<vector<int>> result;
    int target = 5;
    Solution solu;
    result = solu.combinationSum2(candidate, target);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            printf("[%d]", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}