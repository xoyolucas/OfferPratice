// 给定一棵二叉搜索树，请找出其中第k大的节点。

// 示例 1:
// 输入: root = [3,1,4,null,2], k = 1
//    3
//   / \
//  1   4
//   \
//    2
// 输出: 4

// 示例 2:
// 输入: root = [5,3,6,2,4,null,null,1], k = 3
//        5
//       / \
//      3   6
//     / \
//    2   4
//   /
//  1
// 输出: 4
//  
// 限制：
// 1 ≤ k ≤ 二叉搜索树元素个数

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
private:
    int count = 0;
    int res = 0;

public:
    int kthLargest(TreeNode *root, int k)
    {
        if (root == nullptr)
        {
            return -1;
        }
        helper(root, k);

        return res;
    }

    void helper(TreeNode *root, int k)
    {
        if (root->right != nullptr)
        {
            helper(root->right, k);
        }

        count++;
        if (count == k)
        {
            res = root->val;
            return;
        }

        if (root->left != nullptr)
        {
            helper(root->left, k);
        }
    }
};