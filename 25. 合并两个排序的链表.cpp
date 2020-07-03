// 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

// 示例1：
// 输入：1->2->4, 1->3->4
// 输出：1->1->2->3->4->4

// 限制：
// 0 <= 链表长度 <= 1000

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode *begin = nullptr, *next = nullptr;
        if (l1->val <= l2->val)
        {
            begin = l1;
            l1 = l1->next;
        }
        else
        {
            begin = l2;
            l2 = l2->next;
        }
        next = begin;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                next->next = l1;
                next = next->next;
                l1 = l1->next;
            }
            else
            {
                next->next = l2;
                next = next->next;
                l2 = l2->next;
            }
        }
        while (l1 != nullptr)
        {
            next->next = l1;
            next = next->next;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            next->next = l2;
            next = next->next;
            l2 = l2->next;
        }
        return begin;
    }
};

// // 递归
// class Solution
// {
// public
//     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
//     {
//         if (l1 == nullptr)
//         {
//             return l2;
//         }
//         if (l2 == nullptr)
//         {
//             return l1;
//         }
//         if (l1->val <= l2->val)
//         {
//             l1->next = mergeTwoLists(l1->next, l2);
//             return l1;
//         }
//         else
//         {
//             l2->next = mergeTwoLists(l1, l2->next);
//             return l2;
//         }
//     }
// }