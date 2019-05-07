//
// 用两个队列实现栈，剑指offer面试题9相关题目，leetcode225
// Created by chester on 19-4-21.
//

#include <iostream>
#include <queue>

using namespace std;

class Mystack{
public:
    /** Push element x onto stack. */
    void push(int x) {
        if (this->empty())
            queue1.push(x);
        else
        {
            if(queue1.empty() && !queue2.empty())
                queue2.push(x);
            if(queue2.empty() && !queue1.empty())
                queue1.push(x);
        }

    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res;
        if (this->empty())
            return -1;
        if (queue1.empty() && !queue2.empty())
        {
            while(&(queue2.front()) != &(queue2.back()))
            {
                res = queue2.front();
                queue2.pop();
                queue1.push(res);
            }
            res = queue2.front();
            queue2.pop();
        }

        else if (queue2.empty() && !queue1.empty())
        {
            while (&(queue1.front()) != &(queue1.back()))
            {
                res = queue1.front();
                queue1.pop();
                queue2.push(res);
            }
            res = queue1.front();
            queue1.pop();
        }else
            res = -1;
        return res;

    }

    /** Get the top element. */
    int top() {
        int res;
        if (this->empty())
            return -1;
        if (queue1.empty() && !queue2.empty())
        {
            res = queue2.back();
        }
        else if (queue2.empty() && !queue1.empty())
        {
            res = queue1.back();
        }
        else
            res = -1;
        return res;

    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return queue1.empty() && queue2.empty();
    }

private:
    queue<int> queue1;
    queue<int> queue2;
};


int main()
{
    Mystack mystack;
    //cout<<mystack.empty();
    for (int i = 0; i < 5; ++i) {
        mystack.push(i);
    }


    while(!mystack.empty())
    {
        cout << mystack.top() << " ";
        cout << mystack.pop() << endl;
    }
}