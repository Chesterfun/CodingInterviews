//
// Created by chester on 19-5-6.
// 剪绳子：长度为n的绳子剪成m段，求剪完之后各段绳子长度乘积的最大值  （动态规划解法）
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxProduct(int length)
    {
        if (length < 2) return 0;
        if (length == 2) return 1;
        if (length == 3) return 2;
        
        int *products = new int[length+1];
        products[0] = 0;
        products[1] = 1;
        products[2] = 2;
        products[3] = 3;
        
        int max = 0;
        for (int i = 4; i <= length ; ++i) {
            max = 0;
            for (int j = 1; j <= i/2; ++j) {
                int product = products[j]*products[i-j];
                if(max < product)
                    max = product;
                
                products[i] = max;
            }
        }
        
        max = products[length];
        delete []products;
        return max;
    }
};


int main()
{
    Solution solution;
    cout << solution.maxProduct(8) <<endl;
    return 0;
}
