//二维数组中的查找

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool Find(vector<vector<int>> array, int target)
    {
        bool res = false;
        int row = array.size();
        int col = array[0].size();

        for (int i = 0, j = col - 1; (i >= 0 && i < row)&&(j >= 0 && j< col); )
        {
            if(target == array[i][j])
            {
                res = true;
                break;
            }
            else if(target < array[i][j])
                j--;
            else
                i++;
        }
        return res;
    }
};


int main() {
    int a1[] = { 1, 2, 8, 9, };
    int a2[] = { 2, 4, 9, 12, };
    int a3[] = { 4, 7, 10, 13, };
    int a4[] = { 6, 8, 11, 15, };
    vector<vector<int>> array;
    array.push_back(vector<int>(a1, a1 + 4));
    array.push_back(vector<int>(a2, a2 + 4));
    array.push_back(vector<int>(a3, a3 + 4));
    array.push_back(vector<int>(a4, a4 + 4));

    Solution solu;
    cout <<solu.Find(array, 7) <<endl;

    return 0;
}