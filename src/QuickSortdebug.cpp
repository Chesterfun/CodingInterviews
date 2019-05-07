//
// Created by chester on 19-4-22.
//
#include <iostream>
using namespace std;

void exchange(int * a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void print_arr(int *a, int size)  //打印函数
{
    cout << "打印数组：";
    for (int i = 0; i<size; i++)    //打印数组
    {
        cout << a[i] << " ";
    }
    cout << endl << endl;
}

int  partition(int a[], int p, int r) {
    int key = a[r];//取最后一个
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (a[j] <= key)
        {
            i++;
            //i一直代表小于key元素的最后一个索引，当发现有比key小的a[j]时候，i+1 后交换
            exchange(&a[i], &a[j]);
        }
    }
    exchange(&a[i + 1], &a[r]);//将key切换到中间来，左边是小于key的，右边是大于key的值。
    return i + 1;
}

void quickSort(int a[], int p, int r) {
    int position = 0;
    if (p<r)
    {
        position = partition(a,p,r);//返回划分元素的最终位置
        quickSort(a,p,position-1);//划分左边递归
        quickSort(a, position + 1,r);//划分右边递归
    }
}



int main() {
    int d[] = { 6,4,1,8,7,5 };
    cout << "输入数组  {  6,4,1,8,7,5 } " << endl;
    quickSort(d, 0, 5);
    print_arr(d, 6);
    return 0;

}


