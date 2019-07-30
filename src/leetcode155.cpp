//
// Created by chester on 19-7-30.
// 包含min函数的栈：设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
// 思路：设置一个存储数据的栈，一个存储最小数据的栈_min，_min的栈顶元素为当前最小值。每次_data栈push()元素时，把当前最小值push入_min栈, _data栈pop()时，同时也把_min栈顶元素弹出
//

#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        _data.push(x);
        if (_min.empty())
            _min.push(x);
        else {
            if (x > _min.top())
                x = _min.top();
            _min.push(x);
        }
    }

    void pop() {
        _data.pop();
        _min.pop();
    }

    int top() {
        return _data.top();
    }

    int getMin() {
        return _min.top();
    }

private:
    stack<int> _data;
    stack<int> _min;
};

int main() {
    MinStack minStack;
    minStack.push(0);
    minStack.push(5);
    minStack.push(4);
    minStack.push(-1);

    cout << "top() = " << minStack.top() << endl;
    cout << "getMin() = " << minStack.getMin() << endl;
    minStack.pop();
    minStack.push(-6);
    cout << "top() = " << minStack.top() << endl;
    cout << "getMin() = " << minStack.getMin() << endl;

    return 0;
}

