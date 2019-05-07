//
// Created by chester on 19-4-22.
// 快速排序算法
//

#include <iostream>

using namespace std;

class Solution{
public:
    int Partition1(int data[], int start, int end)
    {
        int key = data[end];
        int i = start - 1;
        for (int j = start; j < end; ++j) {
            if (data[j] <= key)
            {
                i++;
                if (i != j)
                    Swap(data[i],data[j]);
            }
        }
        Swap(data[i+1],data[end]);

        return i+1;
    }

    int Partition2(int data[], int start, int end)
    {
        int key = data[start];
        while(start < end)
        {
            while (start<end && data[end] >= key) end--;

            data[start] = data[end];

            while (start<end && data[start] <= key) start++;

            data[end] = data[start];

        }
        data[start] = key;
        return start;

    }

    void QuickSort(int data[], int start, int end)
    {
        if (start<end)
        {
            int index = Partition2(data,start,end);
            QuickSort(data, start, index-1);
            QuickSort(data, index+1, end);
        }

    }

    void Swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

};

void print_arr(int *a, int size)  //打印函数
{
    for (int i = 0; i<size; i++)    //打印数组
    {
        cout << a[i] << " ";
    }
    cout << endl << endl;
}


int main()
{
    int d[] = { 6,1,2,7,5,3,5};
    Solution solu;
    cout << "排序前：" << endl;
    print_arr(d, 7);
    solu.QuickSort(d, 0, 6);
    cout << "排序后：" << endl;
    print_arr(d,7);
    return 0;
}