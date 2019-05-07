//
// Created by chester on 19-4-22.
// 下一个排列
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void nextPermutation(vector<int>& nums) {

        int vioIndex = nums.size() -1 ;
        while(vioIndex > 0)
        {
            if (nums[vioIndex-1] < nums[vioIndex])
                break;
            vioIndex--;
        }

        if(vioIndex > 0)
        {
            vioIndex--;
            int rightIndex = nums.size() - 1;
            while (rightIndex >= 0 && nums[rightIndex] <= nums[vioIndex])
            {
                rightIndex--;
            }

            int temp = nums[vioIndex];
            nums[vioIndex] = nums[rightIndex];
            nums[rightIndex] = temp;
            vioIndex++;

        }

        int end = nums.size() - 1;
        while (end > vioIndex)
        {
            int temp = nums[vioIndex];
            nums[vioIndex] = nums[end];
            nums[end] = temp;
            end--;
            vioIndex++;
        }


    }
};


int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(3);
    nums.push_back(2);
    Solution solu;
    solu.nextPermutation(nums);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] ;
    }
    cout << endl;
    return 0;
}