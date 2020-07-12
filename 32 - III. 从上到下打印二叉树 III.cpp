// 请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，
// 第三行再按照从左到右的顺序打印，其他行以此类推。

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
//   [20,9],
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
#include <vector>
#include <deque>
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

        deque<TreeNode *> level;
        level.push_back(root);

        while (!level.empty())
        {
            int size = level.size();
            deque<int> tmp;
            for (int i = 0; i < size; i++)
            {
                if (res.size() % 2 == 0) //偶数行
                    tmp.push_back(level.front()->val);
                else // 奇数行
                    tmp.push_front(level.front()->val);
                if (level.front()->left != nullptr)
                {
                    level.push_back(level.front()->left);
                }
                if (level.front()->right != nullptr)
                {
                    level.push_back(level.front()->right);
                }
                level.pop_front();
            }
            res.push_back(vector<int>(tmp.begin(), tmp.end()));
        }

        return res;
    }
};