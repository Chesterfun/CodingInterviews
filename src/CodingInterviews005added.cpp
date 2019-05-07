//
// Created by chester on 19-4-16.
// 合并两个有序数组
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
    void mergearray(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {

        int i = m-1, j = n-1;
        int Max = m+n-1;

        while (i>=0 && j>=0)
        {
            nums1[Max--] = max<int>(nums1[i],nums2[j]);
            if(nums1[i] <= nums2[j])
                j--;
            else
                i--;
        }

        while (i < 0 && Max >= 0)
        {
            nums1[Max--] = nums2[j--];
        }


        while (j < 0 && Max >= 0)
        {
            nums1[Max--] = nums1[i--];
        }


    }
};

int main()
{
    int m=3, n=1;
    int array1[] = {1,2,5,0};

    int array2[] = {1};

    vector<int> v1(array1, array1+m+n);
    vector<int> v2(array2, array2+n);


    Solution solu;
    solu.mergearray(v1, m, v2, n);


    for(int i = 0; i<v1.size(); i++)
        cout<<v1[i];
    cout<<endl;


};

