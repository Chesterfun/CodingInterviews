//
// Created by chester on 19-7-26.
// 分隔链表。给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前，保留两个分区中每个节点的初始相对位置。
// 思路：设置两个临时的头节点left_head和right_head， 遍历链表，如果当前链表节点值小于x, 则把节点接在left后面， 如果当前节点大于等于x，则接在right后面
// 最后连接小的那一段链表和大于等于的那一段链表
//
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode left_head(-1);                    //设置两个临时的头节点
        ListNode right_head(-1);
        ListNode *pleftNode = &left_head;          //对应指针指向这两个头节点
        ListNode *prightNode = &right_head;

        ListNode *pcur = head;
        while(pcur) {
            if(pcur->val < x) {
                pleftNode->next = pcur;             //节点值小于x则将该节点插在pleftNode后面
                pleftNode = pcur;                   //pleftNode向后移动
            }
            else {
                prightNode->next = pcur;           //节点值大于等于x则插在prightHead后
                prightNode = pcur;                 //prightNode向后移动
            }
            pcur = pcur->next;
        }

        pleftNode->next = right_head.next;         //将left链表尾与right链表头连接
        prightNode->next = nullptr;                //尾节点next置空
        return left_head.next;                     //返回left链表临时头节点的next节点，即为新链表头节点
    }
};

int main()
{
    ListNode listNode[5] = {1, 6, 3, 2, 5};
    listNode[0].next = &listNode[1];
    listNode[1].next = &listNode[2];
    listNode[2].next = &listNode[3];
    listNode[3].next = &listNode[4];
    listNode[4].next = nullptr;

    Solution solu;
    ListNode *head = solu.partition(listNode, 3);

    while (head){
        cout << head->val <<endl;
        head = head->next;
    }

    return 0;
}