//
// Created by chester on 19-7-25.
// 反转链表升级，反转从位置m到n的链表，用一趟扫描完成反转
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        int rLength = n-m+1;                    //需要逆置的节点个数
        ListNode *newHead = head;               //初始化最终返回的头节点，非特殊情况即原头节点
        ListNode *preHead = nullptr;            //初始化开始反转的节点的前驱

        while (head && --m){                    //将head向前移动m-1个位置
            preHead = head;                     //记录head的前驱
            head = head->next;                  //head一直后移，最终将指向反转段尾节点的后继节点
        }

        ListNode *modifyTail = head;            //modifyTail指向当前的head，即反转后的反转段尾节点
        ListNode *newBetweenHead = nullptr;     //初始化反转段的最终的头节点，开始进行反转段链表反转

        while (head && rLength){
            ListNode *pNext = head->next;
            head->next = newBetweenHead;
            newBetweenHead = head;
            head = pNext;
            rLength--;
        }                                       //反转段反转结束，head最终指向反转段的后继节点

        modifyTail->next = head;                //链接反转后的段尾节点和反转段的后继节点

        if(preHead){                            //如果preHead不为空，即m>1，不是从第一个节点开始反转
            preHead->next = newBetweenHead;     //则连接反转段头节点的前驱与反转后反转段的头节点
        }
        else{
            newHead = newBetweenHead;           //否则从第一个节点开始反转，需要返回的节点就是反转之后反转段的头节点
        }
        return newHead;
    }
};


int main()
{
    ListNode nodelists[5] = {9,8,7,6,5};
    nodelists[0].next = &nodelists[1];
    nodelists[1].next = &nodelists[2];
    nodelists[2].next = &nodelists[3];
    nodelists[3].next = &nodelists[4];
    nodelists[4].next = nullptr;

    Solution solu;
    ListNode *head = solu.reverseBetween(nodelists, 2, 5);

    while (head)
    {
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}