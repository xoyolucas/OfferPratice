// 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，
// 满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

// 例如，给定如下二叉树:  root = [3,5,1,6,2,0,8,null,null,7,4]

// 示例 1:
// 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// 输出: 3
// 解释: 节点 5 和节点 1 的最近公共祖先是节点 3。

// 示例 2:
// 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// 输出: 5
// 解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。

// 说明:
// 所有节点的值都是唯一的。
// p、q 为不同节点且均存在于给定的二叉树中。

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
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (root->val == p->val || root->val == q->val)
        {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left != nullptr && right != nullptr)
        {
            return root;
        }
        else if (left != nullptr)
        {
            return left;
        }
        else if (right != nullptr)
        {
            return right;
        }

        return nullptr;
    }
};

// 非递归
// 前序遍历根节点到p和到q的两个路径（注意剪枝） 然后两个路径逐个比对，最后一个相同的节点即为公共节点
// public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
//     //根节点到p节点的路径
//     List<TreeNode> path1 = new ArrayList<>();
//     //根节点到q节点的路径
//     List<TreeNode> path2 = new ArrayList<>();
//     getPath(root,p,path1);
//     getPath(root,q,path2);

//     TreeNode result=null;
//     int n = Math.min(path1.size(),path2.size());
//     //保留最后一个相等的节点即为公共节点
//     for(int i=0;i<n;i++){
//         if(path1.get(i)==path2.get(i))
//             result = path1.get(i);
//     }
//     return result;
// }
// //前序遍历搜索节点p或q
// void getPath(TreeNode root,TreeNode node,List<TreeNode> path){
//     if(root==null)
//         return ;
//     path.add(root);
//     if(root == node)
//         return ;
//     if(path.get(path.size()-1)!=node){
//         getPath(root.left,node,path);
//     }
//     if(path.get(path.size()-1)!=node){
//         getPath(root.right,node,path);
//     }
//     if(path.get(path.size()-1)!=node){
//         path.remove(path.size()-1);
//     }
// }