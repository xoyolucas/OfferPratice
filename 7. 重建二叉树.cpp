// 输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。

// 例如，给出
// 前序遍历 preorder = [3,9,20,15,7]
// 中序遍历 inorder = [9,3,15,20,7]

// 返回如下的二叉树：
//     3
//    / \
//   9  20
//     /  \
//    15   7

// 限制：
// 0 <= 节点个数 <= 5000

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        TreeNode *root = helper(preorder, inorder, 0, 0, inorder.size() - 1);
        return root;
    }

    TreeNode *helper(vector<int> &preorder, vector<int> &inorder, int head, int begin, int end)
    {
        if (begin > end)
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[head]);
        int index;
        for (index = begin; index <= end; index++)
        {
            if (inorder[index] == preorder[head])
            {
                break;
            }
        }
        root->left = helper(preorder, inorder, head + 1, begin, index - 1);
        root->right = helper(preorder, inorder, head + index - begin + 1, index + 1, end);

        return root;
    }
};