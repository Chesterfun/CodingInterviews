//
// Created by chester on 19-8-2.
// 跳跃游戏：给定一个非负整数数组，你最初位于数组的第一个位置。数组中的每个元素代表你在该位置可以跳跃的最大长度。判断你是否能够到达最后一个位置。
// 输入: [2,3,1,1,4]
// 输出: true
// 解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
// 输入: [3,2,1,0,4]
// 输出: false
// 解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
//
// 思路：贪心算法。
// 若此时处在第i位置,该位置最远可以跳至第j位置(index[i]),故第i位置一定还可跳至:第i+1、i+2、...、j-1、j位置;要想达到最尾的位置，即看跳最远能不能跳到最后的位置。
// 假设从第i个位置最远可跳至第index[i]的位置。那么要想接着能继续跳最远，从第i位应 跳至 第i+1、i+2、...、j-1、j位中可以跳的 更远位置的位置 ,即
// index[i+1]、index[i+2]、...、index[j-1]、index[j] 最大的那个!
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> index;
        for (int i = 0; i < nums.size(); ++i) {
            index.push_back(i + nums[i]);                   //记录从第i位置最远可跳到index[i]位置
        }

        int max_index = index[0];
        int jump = 0;                                        //设置jump为当前所处的位置，从位置0开始跳
        while (jump <= max_index && jump < nums.size()) {    //直到jump超越了当前可以跳的最远位置或者跳至了数组尾部，则不能继续跳下去，循环终止
            if (index[jump] > max_index) {
                max_index = index[jump];
            }
            jump++;
        }
        if (jump == nums.size()) {                          //如果最终jump为数组长度，则返回true
            return true;
        }
        return false;
    }
};

int main() {
    vector<int> nums = {2,1,1,0,4,2};
    Solution solu;
    cout << solu.canJump(nums) << endl;
    return 0;
}


