//
// Created by shmil on 2019/9/1.
// 拼多多机试题 给定输入，输出按如下优先级排列：偶数全部在奇数前面；如果同为奇数或者同为偶数，则数值大的在数值小的前面
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int &x, int &y) {
    return x > y;
}

int main() {
    int n,x;
    char y;
    vector<int> even;
    vector<int> odd;
    while (cin >> x) {
        if (x%2 == 0)
            even.push_back(x);
        else
            odd.push_back(x);
        cin >> y;
        if (y == ';') {
            break;
        }
    }
    cin >> n;

    sort(even.begin(), even.end(), cmp);
    sort(odd.begin(), odd.end(), cmp);

    for (int i = 0; i < n-1; ++i) {
        if (i < even.size()) {
            cout << even[i] << ",";
        } else {
            cout << odd[i - even.size()] << ",";
        }
    }
    if (even.size() >= n) {
        cout << even[n - 1];
    } else {
        cout << odd[n - even.size() - 1];
    }

////    scanf("%d", &x);
////    scanf("%c", &y);
//    while (y == ',') {
//        if (x%2 == 0)
//        {
//            even.push_back(x);
////            printf("even = %d\n", x);
//        }
//        else {
//            odd.push_back(x);
////            printf("odd = %d\n", x);
//        }
//        scanf("%d", &x);
//        scanf("%c", &y);
//    }
//    if (x%2 == 0) {
//        even.push_back(x);
//    }
//    else {
//        odd.push_back(x);
//    }
//    if (y == ';') {
//        scanf("%d", &n);
//    }
////    printf("n = %d\n", n);
//
//    sort (even.begin(), even.end());
//    sort (odd.begin(), odd.end());
//
////    for (int i = 0; i < even.size(); i++) {
////        printf("--- even ---%d\n", even[i]);
////    }
////    for (int i = 0; i < odd.size(); i++) {
////        printf("--- odd ---%d\n", odd[i]);
////    }
//
//    int index = 0;
//    while (!even.empty() && index < n-1) {
//        printf("%d,", *(even.end()-1));
//        even.pop_back();
//        index++;
//    }
//    if (!even.empty() && index == n-1) {
//        printf("%d", *(even.end()-1));
//        even.pop_back();
//        return 0;
//    }
//
//    while(index < n-1 && !odd.empty()) {
//        printf("%d,", *(odd.end()-1));
//        odd.pop_back();
//        index++;
//    }
//    printf("%d", *(odd.end()-1));
    return 0;
}