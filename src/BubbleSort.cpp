//
// Created by chester on 19-4-29.
// 冒泡排序
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void BubbleSort(vector<int> &A, int n)
    {
        for (bool sorted = false; sorted = !sorted; n--)
            for (int i = 1; i < n ; ++i) {

                if (A[i-1] > A[i]){
                    Swap(A[i-1],A[i]);
                    sorted = false;
                }
        }
    }

    void newBubbleSort(vector<int> &A, int n)            //改进版本的冒泡排序
    {
        for (bool sorted = false; sorted == false; n--)  //sorted 记录是否已经全局有序，若有序则不需要继续扫描到n最小
        {
            for (int i = 1; i < n; ++i) {
                sorted = true;                 //先假设有序，若有交换，则之前的排列是无序的；再扫描下一轮默认有序，若无交换则总体有序
                if (A[i-1] > A[i]){
                    sorted = false;
                    Swap(A[i-1],A[i]);
                }
            }
        }
    }


    void print_arr(vector<int> a)  //打印数组函数
    {
        for (int i = 0; i<a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << endl << endl;
    }

private:
    void Swap(int & a1, int & a2)
    {
        int temp = a1;
        a1 = a2;
        a2 = temp;
    }


};

int main()
{
    vector<int> a;
    a.push_back(3);
    a.push_back(7);
    a.push_back(5);
    a.push_back(4);

    Solution solu;
    solu.print_arr(a);
    solu.newBubbleSort(a,4);
    solu.print_arr(a);

    return 0;

}