//
// Created by chester on 19-4-30.
// 合并两个有序链表
//

#include <iostream>

using namespace std;



 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        else if(l2 == nullptr)
            return l1;

        ListNode *pMergeHead = nullptr;
        if (l1->val < l2->val){
            pMergeHead = l1;
            pMergeHead->next = mergeTwoLists(l1->next, l2);
        } else
        {
            pMergeHead = l2;
            pMergeHead->next = mergeTwoLists(l1,l2->next);
        }
        return pMergeHead;

    }
};

void print_list(ListNode * list)
{
    do
        cout << list->val << " ";
    while (list = list->next);
    cout << endl;
}

int main( )
{
    ListNode list1[4] = {1,3,5,7};
    list1[0].next = &list1[1];
    list1[1].next = &list1[2];
    list1[2].next = &list1[3];
    list1[3].next = NULL;

    ListNode list2[4] = {2,4,6,8};
    list2[0].next = &list2[1];
    list2[1].next = &list2[2];
    list2[2].next = &list2[3];
    list2[3].next = NULL;
    print_list(list1);
    print_list(list2);
    Solution solu;
    ListNode *mergeNode = solu.mergeTwoLists(list1,list2);
    print_list(mergeNode);
    return 0;
}