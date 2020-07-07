// 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。

// 例如:
// 给定二叉树: [3,9,20,null,null,15,7],
//     3
//    / \
//   9  20
//     /  \
//    15   7

// 返回其层次遍历结果：
// [
//   [3],
//   [9,20],
//   [15,7]
// ]

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

#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        if (root == nullptr)
        {
            return res;
        }

        queue<TreeNode *> level;
        level.push(root);

        while (!level.empty())
        {
            int size = level.size();
            vector<int> tmp;
            for (int i = 0; i < size; i++)
            {
                tmp.push_back(level.front()->val);
                if (level.front()->left != nullptr)
                {
                    level.push(level.front()->left);
                }
                if (level.front()->right != nullptr)
                {
                    level.push(level.front()->right);
                }
                level.pop();
            }
            res.push_back(tmp);
        }

        return res;
    }
};