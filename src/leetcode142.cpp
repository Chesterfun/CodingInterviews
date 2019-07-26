//
// Created by chester on 19-7-26.
// 环形链表，返回链表开始入环的第一个节点；如果链表无环，返回NULL
// 思路：快慢指针，慢指针一次移动一个节点，快指针一次移动两个节点，若是环形链表，则两指针终将相遇
// 可以证明在相遇的那个节点meet到链表入环的第一个节点的距离和首节点head到入环的第一个节点距离相同，则分别从meet和head出发，第一次相遇即为入环首节点
//
#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *meet = nullptr;

        while(fast) {
            fast = fast->next;                      //fast和slow每次分别先走一步
            slow = slow->next;
            if (!fast)
                return nullptr;
            fast = fast->next;                      //fast还没有到空节点则继续走一步，相当于fast每个循环走两步
            if (fast == slow) {
                meet = fast;
                break;
            }
        }
        if (meet == nullptr)
            return nullptr;

        while (head && meet)
        {
            if (head == meet)
                return head;
            head = head->next;
            meet = meet->next;
        }

        return nullptr;
    }
};

int main()
{
    ListNode listNode[5] = {1,2,3,4,5};
    listNode[0].next = &listNode[1];
    listNode[1].next = &listNode[2];
    listNode[2].next = &listNode[3];
    listNode[3].next = &listNode[4];
    listNode[4].next = &listNode[1];

    Solution solu;
    ListNode *meetNode = solu.detectCycle(listNode);

    cout << meetNode->val << endl;
    return 0;
}