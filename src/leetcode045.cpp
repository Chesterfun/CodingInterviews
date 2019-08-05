//
// Created by chester on 19-8-5.
// 跳跃游戏升级版：(第一版为leetcode055)给定一个非负整数数组，你最初位于数组的第一个位置。
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。
// 你的目标是使用最少的跳跃次数到达数组的最后一个位置。假设你总是可以到达数组的最后一个位置。
//
// 思路：在leetcode055的基础上，继续贪心思想。
// 在到达某点前 若一直不跳跃,发现从该点不能跳到更远的地方了,在这之前肯定有次必要的跳跃!
// 结论 :在无法到达更远的地方时,在这之前应该跳到一个可以到达更远位置的位置!
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        int current_max_index = nums[0];
        int pre_max_max_index = nums[0];
        int jump_min = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (i > current_max_index) {                 //若无法向前移动了，才进行跳跃，直接跳跃到当前可到达的最远的位置
                jump_min++;
                current_max_index = pre_max_max_index;
            }
            if (pre_max_max_index < nums[i] + i) {
                pre_max_max_index = nums[i] + i;
            }
        }
        return jump_min;
    }
};

int main() {
    vector<int> nums = {2,3,1,1,4};
    Solution solu;
    cout << solu.jump(nums) << endl;
    return 0;
}