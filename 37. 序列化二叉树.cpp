// 请实现两个函数，分别用来序列化和反序列化二叉树。

// 示例: 
// 你可以将以下二叉树：
//     1
//    / \
//   2   3
//      / \
//     4   5

// 序列化为 "[1,2,3,null,null,4,5]"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <string>
#include <queue>
#include <vector>
using namespace std;

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string res = "";

        if (root == nullptr)
            return res;

        queue<TreeNode *> tmp;
        tmp.push(root);
        while (!tmp.empty())
        {
            TreeNode *top = tmp.front();
            if (top != nullptr)
            {
                res += to_string(top->val) + ',';
                tmp.push(top->left);
                tmp.push(top->right);
            }
            else
            {
                res += "null,";
            }
            tmp.pop();
        }

        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return nullptr;

        vector<TreeNode *> nodes;
        string str = "";
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] != ',')
            {
                str += data[i];
            }
            else
            {
                if (str != "null")
                {
                    nodes.emplace_back(new TreeNode(stoi(str)));
                }
                else
                {
                    nodes.emplace_back(nullptr);
                }
                str = "";
            }
        }

        int index = 1;
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i] == nullptr)
                continue;
            nodes[i]->left = nodes[index++];
            nodes[i]->right = nodes[index++];
        }

        return nodes[0];
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));