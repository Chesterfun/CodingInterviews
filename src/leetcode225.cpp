//
// Created by chester on 19-7-30.
// 用两个队列实现栈
//

#include <iostream>
#include <queue>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        queue<int> temp_que;
        temp_que.push(x);
        while (!_data.empty()) {
            temp_que.push(_data.front());
            _data.pop();
        }
        while (!temp_que.empty()) {
            _data.push(temp_que.front());
            temp_que.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = _data.front();
        _data.pop();
        return x;
    }

    /** Get the top element. */
    int top() {
        return _data.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return _data.empty();
    }

    int size() {
        return _data.size();
    }

private:
    queue<int> _data;
};

int main() {
    MyStack S;
    if (S.empty())
        cout << "Stack S is empty!" << endl;
    S.push(1);
    S.push(2);
    S.push(3);
    cout << "S.size() = " << S.size() << endl;
    cout << "S.top() = " << S.top() << endl;
    cout << "S.pop() = " << S.pop() <<endl;
    cout << "after pop(): " << endl;
    cout << "S.size() = " << S.size() << endl;
    cout << "S.top() = " << S.top() << endl;

    return 0;
}
