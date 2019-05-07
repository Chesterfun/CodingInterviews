//
// Created by chester on 19-4-19.
// 用两个栈实现队列
//

#include <iostream>
#include <stack>

using namespace std;

class Solution{
public:
    void push(int ele)
    {
        stackIn.push(ele);
    }

    int pop()
    {
        int val = -1;
        if(this->empty())
            return -1;
        else
        {
            if(stackOut.empty())
            {
                while (!stackIn.empty())
                {
                    val = stackIn.top();
                    stackIn.pop();
                    stackOut.push(val);
                }
            }
            val = stackOut.top();
            stackOut.pop();
        }
        return val;
    }

    bool empty()
    {
        return (stackIn.empty() && stackOut.empty());
    }

    int peek()
    {
        int val = -1;
        if(this->empty())
            return NULL;
        else
        {
            if(stackOut.empty())
            {
                while(!stackIn.empty())
                {
                    val = stackIn.top();
                    stackIn.pop();
                    stackOut.push(val);
                }
            }
            val = stackOut.top();

        }
        return val;
    }

private:
    stack<int> stackIn;
    stack<int> stackOut;
};

int main()
{
    Solution solu;
    solu.push(1);
    solu.push(2);
    solu.push(3);
    solu.push(4);

    while(!solu.empty())
    {
        cout<<"peek = "<<solu.peek();
        cout<<" pop = "<<solu.pop()<<endl;
    }
    return 0;
}