//
// Created by chester on 19-5-12.
// 盛最多水的容器
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int resArea = 0;

        while (start < end)
        {
            int area = min(height[start],height[end]) * (end - start);
            resArea = max(area, resArea);

            if (height[start] < height[end])
                start++;
            else
                end--;
        }

        return resArea;
    }
};


int main()
{
    vector<int> h = {1,8,6,2,5,4,8,3,7};
    Solution solu;

    cout << solu.maxArea(h) << endl;

    return 0;

}

