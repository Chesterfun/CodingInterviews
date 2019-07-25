//
// Created by chester on 19-5-5.
// 两个链表的第一个公共节点
//

#include <iostream>
#include <stack>

using namespace std;

struct ListNode
{
    int val;
    ListNode * next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* FindFirstCommonNode(ListNode *leftHead, ListNode *rightHead)
    {
        ListNode *left = leftHead;
        ListNode *right = rightHead;

        stack<ListNode *> leftStack;
        stack<ListNode *> rightStack;

        /// 结点依次入栈
        while(left != NULL)
        {
            //debug <<left->val <<endl;
            leftStack.push(left);
            left = left->next;
        }

        while(right != NULL)
        {
            //debug <<right->val <<endl;
            rightStack.push(right);
            right = right->next;
        }

        ///  开始同步弹出元素
        while(leftStack.empty() != true
              && rightStack.empty() != true)
        {
            left = leftStack.top();
            right = rightStack.top();

            //debug <<left->val <<", " <<right->val <<endl;

            ///  不相同的元素就是合并的前一个结点
            if(left != right)
            {
                break;
            }
            leftStack.pop();
            rightStack.pop();
        }

        ///  不相同元素的下一个结点就是共同结点
        if(left != right)
        {
            return left->next;
        }
        else
        {
            return NULL;
        }
    }

    ListNode * FindFirstCommonNode1(ListNode * headA, ListNode * headB)
    {
        ListNode * pa = headA;
        ListNode * pb = headB;
        stack<ListNode *> sa;
        stack<ListNode *> sb;
        while (pa != nullptr)
        {
            sa.push(pa);
            pa = pa->next;
        }
        while (pb != nullptr)
        {
            sb.push(pb);
            pb = pb->next;
        }


/*
        while(!sa.empty() && !sb.empty())
        {
            pa = sa.top();
            pb = sb.top();
            if(pa != pb) break;
            sa.pop();
            sb.pop();
        }

        return pa!=pb? pa->next: nullptr;
*/


        pa = sa.top(), pb = sb.top();

        while ( (pa!=headA) && (pb!=headB)) {
            if(pa == pb)
            {
                sa.pop();
                sb.pop();
                pa = sa.top();
                pb = sb.top();
            }
            else
                break;

        }
        return pa!=pb? pa->next: nullptr;
    }

    ListNode * FindFirstCommonNode2(ListNode * headA, ListNode * headB)
    {
        unsigned int la = getListLength(headA);
        unsigned int lb = getListLength(headB);
        int nLengthDif = la - lb;
        ListNode *longHead = headA;
        ListNode *shortHead = headB;
        if(la < lb)
        {
            nLengthDif = lb - la;
            longHead = headB;
            shortHead = headA;
        }

        while(nLengthDif>0)
        {
            longHead = longHead->next;
            nLengthDif--;
        }

        while((longHead != nullptr) && (shortHead != nullptr) && (longHead!=shortHead))
        {
            longHead = longHead->next;
            shortHead = shortHead->next;
        }

        ListNode * firstCommonNode = longHead;

        return firstCommonNode;
    }

private:
    int getListLength(ListNode * head)
    {
        unsigned int length = 0;
        ListNode * p = head;
        while (p != nullptr)
        {
            length++;
            p = p->next;
        }

        return length;
    }


};


int main()
{
    ListNode listNodeCommon[3] = {6,6,6};
    for (int i = 0; i < 2; ++i)
        listNodeCommon[i].next = &listNodeCommon[i+1];
    listNodeCommon[2].next = nullptr;

    ListNode listNodeLeft[5] = {9,1,2,3,4};
    for (int i = 0; i < 4; ++i)
        listNodeLeft[i].next = &listNodeLeft[i+1];
    listNodeLeft[4].next = &listNodeCommon[0];

    ListNode listNodeRight[3] = {5,6,7};
    for (int i = 0; i < 2; ++i)
        listNodeRight[i].next = &listNodeRight[i+1];
    listNodeRight[2].next = &listNodeCommon[0];



    Solution solu;
    ListNode *res = solu.FindFirstCommonNode2(&listNodeLeft[0], &listNodeRight[0]);

    cout << res->val;

    return 0;

}
