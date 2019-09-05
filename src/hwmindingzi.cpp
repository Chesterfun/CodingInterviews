//
// Created by chester on 19-9-5.
// 装修需要n颗钉子，只有4颗和9颗装的，最少要买多少盒才能刚好买够n颗
//

//
// Created by chester on 19-9-4.
//

#include <iostream>

using namespace std;

int minnum(int para) {

    int m,n;
    m = para/9;
    n = para%9;
    int res = m;
    int l;
    if (para < 9) {
        if (para == 4)
            return 1;
        else if (para == 8)
            return 2;
        else
            return -1;
    }
    else
    {
        while (n > 0) {
            if (n % 4 == 0) {
                l = n / 4;
                res = m + l;
                break;
            }
            else {
                m--;
                n += 9;
            }
            if (n > para) {
                return -1;
            }
        }
    }

    return res;
}

int main() {
    int x;
    cin >> x;
    cout << minnum(x);
    return 0;
}
