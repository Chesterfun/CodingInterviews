//
// Created by chester on 19-4-24.
// 旋转排序数组的最小值，剑指offer面试题11，leetcode153
// 假设更一般的情况：旋转数组中存在重复元素
//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMin(vector<int> & nums)
    {
        if (nums.size() == 0)
        {
            cout<<"Empty array!" << endl;
            return 0;
        }

        int left = 0, right = nums.size() - 1;
        int Mid = 0;
        while (nums[left] >= nums[right])
        {
            if (right - left == 1)
            {
                Mid = right;
                break;
            }
            Mid = (left + right)/2;


            // 特例处理：[1,0,1,1,1],[1,1,1,0,1]
            if (nums[left] == nums[right] && nums[left] == nums[Mid])
            {
                int result = nums[left];
                for (int i = left+1; i < right ; ++i) {
                    if(result>nums[i])
                        result = nums[i];
                }
                return result;
            }



            if (nums[Mid] >= nums[left])
            {
                left = Mid;
            } else if (nums[Mid] <= nums[right])
            {
                right = Mid;
            }
        }
        return nums[Mid];

    }
};

void print_arr(vector<int> a)  //打印函数
{
    for (int i = 0; i<a.size(); i++)    //打印数组
    {
        cout << a[i] << " ";
    }
    cout << endl << endl;
}

int main()
{
    vector<int> nums;
    for (int i = 6; i < 9; ++i) {
        nums.push_back(i);
    }

    for (int i = 0; i < 6 ; ++i) {
        nums.push_back(i);
    }
    Solution solu;
    print_arr(nums);
    cout << "Min = " << solu.findMin(nums) << endl;
    return 0;
}


