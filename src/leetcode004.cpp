//
// Created by chester on 19-4-26.
// 寻找两个有序数组的中位数，更通用的形式：给定两个已经排序好的数组，找到两者所有元素中第k大的元素
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size();
        const int n = nums2.size();
        int total = m + n;

        if(total & 0x1)
            return find_kth(nums1.begin(),m,nums2.begin(),n,total/2+1);
        else
            return (find_kth(nums1.begin(),m,nums2.begin(),n,total/2)+
            find_kth(nums1.begin(),m,nums2.begin(),n,total/2+1))/2.0;

    }

private:
    static int find_kth(vector<int>::const_iterator A, int m, vector<int>::const_iterator B, int n, int k)
    {
        //保证m不大于n
        if(m>n) return find_kth(B,n,A,m,k);
        if(m==0) return *(B+k-1);
        if(k==1) return min(*A, *B);

        int ia = min(m,k/2), ib = k-ia;

        if(*(A+ia-1) < *(B+ib-1))
            return find_kth(A+ia,m-ia,B,n,k-ia);
        else if(*(A+ia-1)==*(B+ib-1))
            return A[ia-1];
        else
            return find_kth(A, m, B+ib, n-ib, k-ib);


    }
};



int main()
{
    vector<int> v1, v2;
    for (int i = 0; i < 9; ++i) {
        v1.push_back(i);
    }

    for (int j = 4; j < 8; ++j) {
        v2.push_back(j);
    }

    Solution solu;
    cout << solu.findMedianSortedArrays(v1,v2);


}