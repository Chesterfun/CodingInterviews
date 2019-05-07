//
// Created by chester on 19-4-24.
// 旋转数组
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void rotate(vector<int>& nums, int k) {
        for (int i = 0; i<k; i++)
        {
            int temp = nums[nums.size()-1];
            for (int j = nums.size()-2; j>=0 ; j--) {
                nums[j+1] = nums[j];
            }
            nums[0] = temp;
        }
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
    for(int i = 0; i<5; i++)
    {
        nums.push_back(i);
    }

    print_arr(nums);

    Solution solu;
    solu.rotate(nums, 2);
    print_arr(nums);
    return 0;
}
