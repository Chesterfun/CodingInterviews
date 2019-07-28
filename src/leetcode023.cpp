//
// Created by chester on 19-7-28.
// 合并k个有序链表
// 时间复杂度分析：设有k个链表，平均每个链表有N个节点
// 方法1的时间复杂度： kN*logkN + kN = O(kN*logkN)
// 方法2的时间复杂度： 第一轮，进行k/2次，每一次处理2N个数字；第二轮，进行k/4次，每一次处理4N个数字
//                  2N*k/2 + 4N*k/4 + 8N*k/8 + ... +2^logk * N * k/(2^logk) = Nk + Nk + Nk + ... + Nk = O(kN * logk)
// 方法2的时间复杂度较优
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool cmp(const ListNode *a, const ListNode *b) {
    return a->val < b->val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {          //方法1：将所有的链表节点放入vector中，利用sort函数排序
//        if(lists.size() == 0)
//            return nullptr;
        vector<ListNode *> node_vec;
        for(int i=0; i<lists.size(); i++) {
            ListNode *head = lists[i];
            while(head) {
                node_vec.push_back(head);
                head = head->next;
            }
        }
        if(node_vec.size() == 0)
            return nullptr;
        sort(node_vec.begin(), node_vec.end(), cmp);
        for (int j = 1; j < node_vec.size() ; ++j) {
            node_vec[j-1]->next = node_vec[j];
        }

        node_vec[node_vec.size()-1]->next = nullptr;
        return node_vec[0];
    }

    ListNode *mergeKLists1(vector<ListNode*>& lists) {          //方法2：分而治之
        if(lists.size() == 0)
            return nullptr;
        if(lists.size() == 1)
            return lists[0];
        if(lists.size() == 2)
            return mergeTwoLists(lists[0], lists[1]);

        int mid = lists.size()/2;
        vector<ListNode *> sub_lists1;
        vector<ListNode *> sub_lists2;
        for (int i = 0; i < mid; ++i) {
            sub_lists1.push_back(lists[i]);
        }
        for (int i = mid ; i < lists.size(); ++i) {
            sub_lists2.push_back(lists[i]);
        }

        ListNode *l1 = mergeKLists(sub_lists1);
        ListNode *l2 = mergeKLists(sub_lists2);

        return mergeTwoLists(l1, l2);

    }

private:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {        //两个有序链表的合并
        ListNode temp_head(-1);
        ListNode *phead = &temp_head;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                phead->next = l1;
                l1 = l1->next;
            }
            else {
                phead->next = l2;
                l2 = l2->next;
            }
            phead = phead->next;
        }

        if (l1) {
            phead->next = l1;
        }
        if (l2) {
            phead->next = l2;
        }

        return temp_head.next;
    }
};


int main() {
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

    ListNode list3[4] = {2,5,6,9};
    list3[0].next = &list3[1];
    list3[1].next = &list3[2];
    list3[2].next = &list3[3];
    list3[3].next = NULL;

    vector<ListNode*> lists = {list1, list2, list3};
    Solution solu;
    ListNode *head = solu.mergeKLists1(lists);

    while (head) {
        cout << head->val << endl;
        head = head->next;
    }

    return 0;
}