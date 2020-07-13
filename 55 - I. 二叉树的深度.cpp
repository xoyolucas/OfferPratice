// 输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，
// 最长路径的长度为树的深度。

// 例如：
// 给定二叉树 [3,9,20,null,null,15,7]，

//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回它的最大深度 3 。

// 提示：
// 节点总数 <= 10000

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// #include <algorithm>

// 递归求解
// class Solution
// {
// public:
//     int maxDepth(TreeNode *root)
//     {
//         if (root == nullptr)
//         {
//             return 0;
//         }

//         return std::max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
//     }
// };

// 非递归，层序遍历
#include <queue>
using namespace std;

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (root)
            q.push(root);
        int depth = 0;
        while (q.size())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *tr = q.front();
                q.pop();
                if (tr->left)
                    q.push(tr->left);
                if (tr->right)
                    q.push(tr->right);
            }
            depth++;
        }
        return depth;
    }
};