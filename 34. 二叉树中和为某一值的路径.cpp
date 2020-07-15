// 输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
// 从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。

// 示例:
// 给定如下二叉树，以及目标和 sum = 22，
//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1

// 返回:
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

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
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<int> path;
        bfs(root, sum, path);
        return res;
    }

    void bfs(TreeNode *cur, int target, vector<int> &path)
    {
        if (cur == nullptr)
            return;
        target -= cur->val;
        path.push_back(cur->val);
        if (target == 0 && cur->left == nullptr && cur->right == nullptr)
        {
            res.push_back(path);
        }

        bfs(cur->left, target, path);
        bfs(cur->right, target, path);
        path.pop_back();
    }

private:
    vector<vector<int>> res;
};