//
// Created by chester on 19-4-29.
// 归并排序
//

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    void mergeSort(vector<int> &A, vector<int>::iterator lo, vector<int>::iterator hi)
    {
        if (hi - lo < 2) return;
        vector<int>::iterator mi = lo + (hi - lo)/2;
        mergeSort(A, lo, mi);
        mergeSort(A, mi, hi);
        merge(lo, mi, hi);

    }

    void mergeSortData(int data[], int lo, int hi)
    {
        if(hi-lo<2) return;
        int mi = lo + (hi-lo)/2;
        mergeSortData(data, lo, mi);
        mergeSortData(data, mi, hi);
        mergeData(data, lo, mi, hi);
    }




    void print_arr(vector<int> a)  //打印数组函数
    {
        for (int i = 0; i<a.size(); i++)
        {
            cout << a[i] << " ";
        }
        cout << endl ;
    }

    void print_array(int *data, int n )
    {
        for (int i = 0; i < n; ++i) {
            cout << data[i] << " ";
        }
        cout<<endl;
    }

private:

    void merge(vector<int>::iterator lo, vector<int>::iterator mi, vector<int>::iterator hi) //vector接口
    {
        vector<int>::iterator A = lo;
        int lb = mi - lo; int * B = new int[lb];
        for (int i = 0; i < lb; ++i)  B[i] = *(A+i);
        int lc = hi - mi; vector<int>::iterator C = mi;
        for (int i = 0, j = 0, k = 0; (j < lb)||(k < lc);i++ ) {
            if ((j<lb) && (lc<=k || (B[j]<=*(C+k))))
            {
                *(A+i) = B[j];
                j++;
            }
            else if ((k<lc) && (lb<=j || (*(C+k) <B[j])))
            {
                *(A+i) = *(C+k);
                k++;
            }
        }
        delete []B;
    }

    void mergeData(int data[], int lo, int mi, int hi) //数组接口
    {
        int *A = &data[lo];
        int lb = mi - lo;
        int * B = new int[lb];
        for (int i = 0; i < lb; ++i)  B[i] = A[i];
        int lc = hi - mi; int *C = &data[mi];
        for (int i=0,j=0,k=0; (j<lb)||(k<lc); )
        {
            if ((j<lb) && ((B[j]<=C[k]) || (lc <= k)))
            {
                A[i++] = B[j++];
            }
            else if ((k<lc) && ((C[k]<B[j])|| (lb <= j)))
            {
                A[i++] = C[k++];
            }
        }
        delete []B;
    }


};

int main()
{
    vector<int> a;
    a.push_back(3);
    a.push_back(7);
    a.push_back(5);
    a.push_back(4);

    int data[6] = {2,5,3,6,7,5};

    //vector<int>::const_iterator m = a.begin() + (a.end()-a.begin())/2;



    Solution solu;
    solu.print_arr(a);
    solu.mergeSort(a,a.begin(),a.end());
    solu.print_arr(a);
    solu.print_array(data, 6);
    solu.mergeSortData(data,0,6);
    solu.print_array(data, 6);



    return 0;

}
