//
// Created by chester on 19-8-14.
// 计算右侧小于当前元素的个数（求逆序数）
// 给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。
//
// 示例:
// 输入: [5,2,6,1]
// 输出: [2,1,1,0]
// 思路：最暴力的方法,即对 每个元素 扫描其右侧比它小的数,累加个数。假设数组元素个数为N, 算法复杂度 O(N^2)，超时。
// 考虑在归并两排序数组时，当需要将前一个数组元素的指针i指向的元素插入时,对应的count[i],即为指向后一个数组的指针j的值，考虑在一次归并排序中完成count数组的创建

#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> count;
        vector<pair<int,int>> vec;
        for (int i = 0; i < nums.size(); ++i) {
            vec.push_back(make_pair(nums[i], i));
            count.push_back(0);
        }
        merge_sort(vec, count);
        return count;
    }

private:
    void merge_sort_two_vec(vector<pair<int,int>> &sub_vec1, vector<pair<int,int>> &sub_vec2, vector<pair<int,int>> &vec, vector<int> &count) {
        int i = 0;
        int j = 0;
        while (i < sub_vec1.size() && j < sub_vec2.size()) {
            if (sub_vec1[i].first <= sub_vec2[j].first) {
                count[sub_vec1[i].second] += j;
                vec.push_back(sub_vec1[i]);
                i++;
            }
            else {
                vec.push_back(sub_vec2[j]);
                j++;
            }
        }

        for (; i < sub_vec1.size(); ++i) {
            count[sub_vec1[i].second] += j;
            vec.push_back(sub_vec1[i]);
        }

        for (; j < sub_vec2.size(); ++j) {
            vec.push_back(sub_vec2[j]);
        }
    }

    void merge_sort(vector<pair<int,int>> &vec, vector<int> &count) {
        if (vec.size() < 2)
            return;
        int mid = vec.size()/2;
        vector<pair<int,int>> sub_vec1;
        vector<pair<int,int>> sub_vec2;
        for (int i = 0; i < mid; ++i) {
            sub_vec1.push_back(vec[i]);
        }
        for (int j = mid; j < vec.size(); ++j) {
            sub_vec2.push_back(vec[j]);
        }
        merge_sort(sub_vec1, count);
        merge_sort(sub_vec2, count);
        vec.clear();
        merge_sort_two_vec(sub_vec1, sub_vec2, vec, count);
    }
};

int main() {
    vector<int> nums = {5, -7, 9, 1, 3, 5, -2, 1};
    Solution solu;
    vector<int> result = solu.countSmaller(nums);
    for (int i = 0; i < result.size(); ++i) {
        printf("[%d]", result[i]);
    }
    printf("\n");
    return 0;
}