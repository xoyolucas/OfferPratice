// 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。

// 例如:
// 给定二叉树: [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7

// 返回：
// [3,9,20,15,7]

// 提示：
// 节点总数 <= 1000

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> levelOrder(TreeNode *root)
    {
        vector<int> res;
        if (root == nullptr)
        {
            return res;
        }

        queue<TreeNode *> node;
        node.push(root);

        while (!node.empty())
        {
            int size = node.size();
            while (size--)
            {
                TreeNode *tmp = node.front();
                res.push_back(tmp->val);
                if (tmp->left)
                    node.push(tmp->left);
                if (tmp->right)
                    node.push(tmp->right);
                node.pop();
            }
        }
        return res;
    }
};