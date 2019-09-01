//
// Created by shmil on 2019/9/1.
//

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int x;
    char y;
    vector<int> even;
    vector<int> odd;
    scanf("%d", &x);
    scanf("%c", &y);
    while (y == ',') {
        if (x%2 == 0)
        {
            even.push_back(x);
            //printf("%d\n", x);
        }
        else {
            odd.push_back(x);
        }
        scanf("%d", &x);
        scanf("%c", &y);
    }
    if (x%2 == 0) {
        even.push_back(x);
    }
    else {
        odd.push_back(x);
    }
    if (y == ';') {
        scanf("%d", &n);
    }
    //printf("%d", n);
    sort (even.begin(), even.end());
    sort (odd.begin(), odd.end());
    for (int i = 0; i < even.size(); i++) {
        printf("%d\n", even[i]);
    }
    for (int i = 0; i < odd.size(); i++) {
        printf("%d\n", odd[i]);
    }
    sort (even.begin(), even.end());
    sort (odd.begin(), odd.end());
    int index = 0;
    while (!even.empty() && index < n-1) {
        printf("%d,", *even.end());
        even.pop_back();
        index++;
    }
    if (!even.empty() && index == n-1) {
        printf("%d", *even.end());
        even.pop_back();
        index++;
        return 0;
    }

    while(index < n-1 && !odd.empty()) {
        printf("%d,", *odd.end());
        odd.pop_back();
    }
    printf("%d", *odd.end());
    return 0;
}