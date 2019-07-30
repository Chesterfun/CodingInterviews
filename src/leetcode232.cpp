//
// Created by chester on 19-7-30.
// 使用栈实现队列
// 思路：利用一个临时栈，在push操作里，实现存储数据的栈里的数据顺序反向即可
//

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stack<int> temp_stack;
        while (!_data.empty()) {
            temp_stack.push(_data.top());
            _data.pop();
        }
        temp_stack.push(x);
        while (!temp_stack.empty()) {
            _data.push(temp_stack.top());
            temp_stack.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = _data.top();
        _data.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        return _data.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return _data.empty();
    }

    int size() {
        return _data.size();
    }

private:
    stack<int> _data;
};

int main() {
    MyQueue Q;
    if (Q.empty())
        cout << "Stack S is empty!" << endl;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    cout << "S.size() = " << Q.size() << endl;
    cout << "S.top() = " << Q.peek() << endl;
    cout << "S.pop() = " << Q.pop() <<endl;
    cout << "after pop(): " << endl;
    cout << "S.size() = " << Q.size() << endl;
    cout << "S.top() = " << Q.peek() << endl;

    return 0;
}