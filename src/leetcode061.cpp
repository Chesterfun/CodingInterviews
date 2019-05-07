//
// Created by chester on 19-4-25.
// 旋转链表
//

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode * next;
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;

        int len = 1;
        ListNode * p = head;
        while(p->next)
        {
            len++;
            p=p->next;
        }

        k %= len;

        p->next = head;

        for(int i=0; i<len-k; i++)
        {
            p = p->next;
        }

        head = p->next;
        p -> next = NULL;
        return head;

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

    ListNode * res = solu.rotateRight(list,2);

    while(res->next != NULL)
    {
        cout << res->val << " " << endl;
        res = res->next;
    }
    cout << res->val << " " << endl;



    return 0;
}


