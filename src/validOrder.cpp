//
// Created by chester on 19-7-30.
// 合法的出栈序列：已知从1至n的数字序列，按顺序入栈，每个数字入栈后即可出栈，也可在栈中停留，等待后面的数字入栈出栈后，该数字再出栈，求所给的出栈序列是否合法
// 例如：3-2-5-4-1是合法的；3-1-2-4-5不合法，因为先让3出栈，则1不可能比2先出栈。
// 思路：定义一个栈实际尝试能不能按照所给顺序弹出。将所给的出栈序列压入一个队列中。从1开始依次对照队列的头元素决定入栈出栈操作，若最终栈中元素能全部弹出则为合法序列。
//

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool check_is_valid_order(queue<int> &order) {
    stack<int> S;                                       //S为模拟栈
    int n = order.size();
    for (int i = 1; i <= n; ++i) {                      //依次将1～n按顺序入栈
        S.push(i);
        while (!S.empty() && S.top()==order.front()) {  //每次继续压入一个新数字之前，如果栈顶元素和队列首元素相等则弹出该元素
            S.pop();
            order.pop();
        }
    }
    if (!S.empty())                                     //最终若S不能弹出所有的元素则说明序列不合法
        return false;
    return true;
}

int main() {
    queue<int> order;
    order.push(3);
    order.push(2);
    order.push(5);
    order.push(4);
    order.push(1);

    queue<int> invalid;
    invalid.push(3);
    invalid.push(1);
    invalid.push(2);
    invalid.push(4);
    invalid.push(5);

    cout << check_is_valid_order(order) << endl;
    cout << check_is_valid_order(invalid) << endl;
    return 0;
}

