// 输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。

// 示例 1：
// 输入：head = [1,3,2]
// 输出：[2,3,1]
//  
// 限制：
// 0 <= 链表长度 <= 10000

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <stack>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> reversePrint(ListNode *head)
    {
        stack<int> tmp;
        vector<int> res;

        while (head != NULL)
        {
            tmp.push(head->val);
            head = head->next;
        }
        while (!tmp.empty())
        {
            res.emplace_back(tmp.top());
            tmp.pop();
        }
        return res;
    }
};