//
// Created by chester on 19-4-21.
// 1.斐波那契数列
// 2.青蛙跳阶问题，一次可跳一阶也可跳2阶，问跳n阶有多少种跳法
//

#include <iostream>

using namespace std;

long long Finonacci(unsigned int n)
{
    int result[2] = {0,1};
    if(n<2)
        return result[n];
    long long fibNMinusOne = 1;
    long long fibNMinusTwo = 0;
    long long fibN = 0;
    for (int i = 2; i <= n ; ++i) {
        fibN = fibNMinusOne + fibNMinusTwo;

        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;

    }

    return fibN;
}

long long FrogJumps(unsigned int n)
{
    int result[3] = {0,1,2};
    if (n <= 2)
        return result[n];

    long long fibNMinusOne = 2;
    long long fibNMinusTwo = 1;
    long long fibN = 0;
    for (int i = 3; i <= n; ++i) {
        fibN = fibNMinusOne + fibNMinusTwo;

        fibNMinusTwo = fibNMinusOne;
        fibNMinusOne = fibN;
    }

    return fibN;
}

int main()
{
    cout << Finonacci(10) << endl;
    //cout << Finonacci(5000) << endl;
    cout << FrogJumps(9) << endl;

    return 0;
}
