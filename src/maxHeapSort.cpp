//
// Created by shmil on 2019/9/22.
// 堆排序
// 利用最大堆，将数组最大堆化后，第一次将A[0]与A[n - 1]交换，再对A[0…n-2]重新恢复堆。
// 第二次将A[0]与A[n – 2]交换，再对A[0…n - 3]重新恢复堆，重复这样的操作直到A[0]与A[1]交换。
// 由于每次都是将最大的数据并入到后面的有序区间，故操作完成后整个数组就有序了。
//

#include <bits/stdc++.h>

using namespace std;

void maxHeapFixDown(vector<int> &arr, int i, int n) {
    int tmp = arr[i];
    int j = 2 * i + 1;
    while (j < n) {
        if (arr[j] < arr[j + 1] && j + 1 < n) {
            j++;
        }
        if (arr[j] <= tmp) {
            break;
        }
        arr[i] = arr[j];
        i = j;
        j = 2 * i + 1;
    }
    arr[i] = tmp;
}

void makeMaxHeap(vector<int> &arr, int n){
    for (int i = n / 2 - 1; i >= 0; --i) {
        maxHeapFixDown(arr, i, n);
    }
}

void Swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void maxHeapSort(vector<int> &arr){
    int n = arr.size();
    makeMaxHeap(arr, n);
    for (int i = n-1; i >= 1; --i) {
        Swap(arr[0], arr[i]);
        maxHeapFixDown(arr, 0, i);
    }
}

int main() {
    vector<int> myarr = {20, 19, 67, 2, 38, 6, 100, 0, 29, 17, 34};
    maxHeapSort(myarr);
    for (int i = 0; i < myarr.size(); ++i) {
        cout << myarr[i] << " ";
    }
    return 0;
}
