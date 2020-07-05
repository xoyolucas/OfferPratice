// 请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，
// 还有一个 random 指针指向链表中的任意节点或者 null。

// 示例 1：
// 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]

// 示例 2：
// 输入：head = [[1,1],[2,1]]
// 输出：[[1,1],[2,1]]

// 示例 3：
// 输入：head = [[3,null],[3,0],[3,null]]
// 输出：[[3,null],[3,0],[3,null]]

// 示例 4：
// 输入：head = []
// 输出：[]

// 解释：给定的链表为空（空指针），因此返回 null。

// 提示：
// -10000 <= Node.val <= 10000
// Node.random 为空（null）或指向链表中的节点。
// 节点数目不超过 1000 。

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
#include <unordered_map>
using namespace std;

// 使用hash map复制
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == nullptr)
        {
            return head;
        }

        unordered_map<Node *, Node *> tmp;
        for (Node *cur = head; cur != nullptr; cur = cur->next)
        {
            tmp[cur] = new Node(cur->val);
        }

        for (Node *cur = head; cur != nullptr; cur = cur->next)
        {
            tmp[cur]->next = tmp[cur->next];
            tmp[cur]->random = tmp[cur->random];
        }

        return tmp[head];
    }
};

// // 原地修改
// class Solution
// {
// public:
//     Node *copyRandomList(Node *head)
//     {
//         if (head == nullptr)
//         {
//             return head;
//         }

//         //将拷贝节点放到原节点后面，例如1->2->3这样的链表就变成了这样1->1'->2->2'->3->3'
//         for (Node *cur = head; cur != nullptr; cur = cur->next->next)
//         {
//             Node *copy = new Node(cur->val);
//             copy->next = cur->next;
//             cur->next = copy;
//         }
//         //把拷贝节点的random指针安排上
//         for (Node *cur = head; cur != nullptr; cur = cur->next->next)
//         {
//             if (cur->random != nullptr)
//             {
//                 cur->next->random = cur->random->next;
//             }
//         }

//         //分离拷贝节点和原节点，变成1->2->3和1'->2'->3'两个链表，后者就是答案
//         Node *newHead = head->next;
//         for (Node *cur = head; cur != nullptr && cur->next != nullptr;)
//         {
//             Node *tmp = cur->next;
//             cur->next = tmp->next;
//             cur = tmp;
//         }

//         return newHead;
//     }
// };