//
// Created by chester on 19-4-17.
// 从尾到头打印链表
//


#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode * next;
};

class Solution {
public:
    void PrintListReversingly(ListNode * pHead)
    {
        stack<ListNode*> st;
        ListNode * pnode = pHead;
        while (pnode != nullptr)
        {
            st.push(pnode);
            pnode = pnode -> next;
        }

        while(!st.empty())
        {
            printf("%d", st.top()->val);
            st.pop();
        }


    }
};

int main( )
{
    ListNode list[4];
    list[0].val = 1;
    list[0].next = &list[1];
    list[1].val = 2;
    list[1].next = &list[2];
    list[2].val = 3;
    list[2].next = &list[3];
    list[3].val = 4;
    list[3].next = NULL;



    Solution solu;
    solu.PrintListReversingly(list);

    return 0;
}

