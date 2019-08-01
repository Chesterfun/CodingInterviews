//
// Created by chester on 19-8-1.
// 摇摆序列：如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为摆动序列。第一个差（如果存在的话）可能是正数或负数。少于两个元素的序列也是摆动序列。
// 例如， [1,7,4,9,2,5] 是一个摆动序列，因为差值 (6,-3,5,-7,3) 是正负交替出现的。相反, [1,4,7,2,5] 和 [1,7,4,5,5] 不是摆动序列
// 给定一个整数序列，返回作为摆动序列的最长子序列的长度。 通过从原始序列中删除一些（也可以不删除）元素来获得子序列，剩下的元素保持其原始顺序。
//
// 思路：贪心。当序列有一段 连续的递增(或递减) 时,为形成摇摆子序列 ,我们只需要保留这段连续的递增(或递减)的首尾元素 ,这样更可能使得尾部的后一个元素成为摇摆子序列的下一个元素。
// 状态机转换（BEGIN, UP, DOWN)

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        static const int BEGIN = 0;
        static const int UP = 1;
        static const int DOWN = 2;
        int STATE = BEGIN;
        int max_length = 1;
        for (int i = 1; i < nums.size(); ++i) {
            switch (STATE) {
                case BEGIN:
                    if (nums[i-1] < nums[i]) {
                        STATE = UP;
                        max_length++;
                    }
                    else if (nums[i-1] > nums[i]) {
                        STATE = DOWN;
                        max_length++;
                    }
                    break;
                case UP:
                    if (nums[i-1] > nums[i]) {
                        STATE = DOWN;
                        max_length++;
                    }
                    break;
                case DOWN:
                    if (nums[i-1] < nums[i]) {
                        STATE = UP;
                        max_length++;
                    }
                    break;
            }
        }
        return max_length;
    }
};

int main() {
    vector<int> v1 = {1,7,4,9,2,5};
    vector<int> v2 = {1,17,5,10,13,15,10,5,16,8};
    Solution solu;
    cout << solu.wiggleMaxLength(v1) << endl;
    cout << solu.wiggleMaxLength(v2) << endl;
    return 0;
}


