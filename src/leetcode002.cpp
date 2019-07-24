//
// Created by chester on 19-4-25.
// 两数相加
//

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode * next;
    //ListNode() {}
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(-1); //
        int carry = 0;
        ListNode *prev = &dummy;
        for (ListNode *pa = l1, *pb = l2;
             pa != nullptr || pb != nullptr;
             pa = pa == nullptr ? nullptr : pa->next,
             pb = pb == nullptr ? nullptr : pb->next,
             prev = prev->next) {
            const int ai = pa == nullptr ? 0 : pa->val;
            const int bi = pb == nullptr ? 0 : pb->val;
            const int value = (ai + bi + carry) % 10;
            carry = (ai + bi + carry) / 10;
            prev->next = new ListNode(value); //
        }
        if (carry > 0)
            prev->next = new ListNode(carry);
        return dummy.next;
    }
};


int main()
{
    ListNode list1[4] = {1,2,3,4};
    list1[0].next = &list1[1];
    list1[1].next = &list1[2];
    list1[2].next = &list1[3];
    list1[3].next = NULL;

    ListNode list2[3] = {0,9,1};
    list2[0].next = &list2[1];
    list2[1].next = &list2[2];
    list2[2].next = NULL;

    Solution solu;
    ListNode* res = solu.addTwoNumbers(list1, list2);
    while(res->next != NULL)
    {
        cout << res->val << " " << endl;
        res = res->next;
    }
    cout << res->val << " " << endl;

    for (int i = 0, j = 0; i < 5; ++i, ++j) {

    }
}

