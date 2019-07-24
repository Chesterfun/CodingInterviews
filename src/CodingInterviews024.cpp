//
// Created by chester on 19-7-24.
// 反转链表，剑指offer24题，leetcode206
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * reversedHead = nullptr;

        while(head) {
            ListNode *psucc = head->next;
            head->next = reversedHead;
            reversedHead = head;
            head = psucc;
        }
        return reversedHead;
    }
};

int main()
{
    ListNode nodelists[3] = {1,2,3};
    nodelists[0].next = &nodelists[1];
    nodelists[1].next = &nodelists[2];
    nodelists[2].next = nullptr;
    Solution solu;
    ListNode *head = &nodelists[0];
    cout << "before reverse: " << endl;
    while (head)
    {
        cout << head->val << endl;
        head = head->next;
    }
    head = solu.reverseList(&nodelists[0]);
    cout << "after reverse: " << endl;
    while (head)
    {
        cout << head->val << endl;
        head = head->next;
    }

    return 0;
}