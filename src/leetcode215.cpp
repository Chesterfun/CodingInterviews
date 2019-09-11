//
// Created by chester on 19-7-31.
// 数组中的第K个最大元素
// 思路：首先想到最直接的方法就是将数组的元素从大到小排序后取出第K个元素，但是这个时间复杂度是nlogn。 想到利用最小堆可以达到nlogK的复杂度（当n很大，K比较小的时候nlogn比nlogK大很多）
// 维护一个K大小的最小堆，堆中元素个数小于K时，新元素直接进入堆；否则，当堆顶小于新元素时，弹出堆顶，将新元素加入堆。
// 由于堆是最小堆，堆顶是堆中最小元素, 新元素都会保证比堆顶小 (否则新元素替换堆顶),故堆中K个元素是已扫描的元素里最大的K个;堆顶即为第K大的数。
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> Q;   //初始化最小堆
        for (int i = 0; i < nums.size(); ++i) {
            if (Q.size() < k) {                             //当堆中元素个数小于K时，直接将元素push入堆中
                Q.push(nums[i]);
            }
            else if (nums[i] > Q.top()) {                   //否则当新的元素比堆顶元素大时，说明堆顶元素不是前K大的元素，弹出堆顶元素并将新元素入堆
                Q.pop();
                Q.push(nums[i]);
            }
                                                            //这里隐含另一种情况，当新元素比堆顶元素小时，不执行任何操作直接continue遍历下一个元素即可
        }
        return Q.top();
    }
};

int main() {
    vector<int> nums = {-1,2,0,9};
    Solution solu;
    cout << solu.findKthLargest(nums,2) << endl;
    return 0;
}