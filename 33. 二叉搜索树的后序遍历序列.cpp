// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。
// 假设输入的数组的任意两个数字都互不相同。

// 参考以下这颗二叉搜索树：
//      5
//     / \
//    2   6
//   / \
//  1   3
// 示例 1：
// 输入: [1,6,3,2,5]
// 输出: false

// 示例 2：
// 输入: [1,3,2,6,5]
// 输出: true

// 提示：
// 数组长度 <= 1000

#include <vector>
using namespace std;

class Solution
{
public:
    bool verifyPostorder(vector<int> &postorder)
    {
        return helper(postorder, 0, postorder.size() - 1);
    }

    bool helper(vector<int> &postorder, int i, int j)
    {
        if (i >= j)
            return true;

        int tmp = i;
        while (postorder[tmp] < postorder[j])
            tmp++; // 找到右子树起始点
        int m = tmp;
        while (postorder[tmp] > postorder[j])
            tmp++; // 保证右子树合法

        return tmp == j && helper(postorder, i, m - 1) && helper(postorder, m, j - 1);
    }
};

// 递归解析：
// 终止条件： 当 i≥j ，说明此子树节点数量≤1 ，无需判别正确性，因此直接返回 true；
// 递推工作：
// 划分左右子树： 遍历后序遍历的 [i, j]区间元素，寻找第一个大于根节点的节点，索引记为m。
// 此时，可划分出左子树区间 [i,m-1]、右子树区间 [m, j - 1]、根节点索引 j。
// 判断是否为二叉搜索树：
// 左子树区间 [i, m - 1]内的所有节点都应 <postorder[j] 。而第1.划分左右子树步骤已经保证左子树区间的正确性，
// 因此只需要判断右子树区间即可。
// 右子树区间 [m, j-1]内的所有节点都应 >postorder[j] 。实现方式为遍历，当遇到≤postorder[j]的节点则跳出；
// 则可通过 p = j 判断是否为二叉搜索树。
// 返回值： 所有子树都需正确才可判定正确，因此使用 与逻辑符&&连接。
// p = j： 判断此树是否正确。
// recur(i, m - 1)： 判断 此树的左子树 是否正确。
// recur(m, j - 1)： 判断 此树的右子树 是否正确。


// 单调栈/单调栈/单调栈
// class Solution {
//     public boolean verifyPostorder(int[] postorder) {
//         // 单调栈使用，单调递增的单调栈
//         Deque<Integer> stack = new LinkedList<>();
//         // 表示上一个根节点的元素，这里可以把postorder的最后一个元素root看成无穷大节点的左孩子
//         int pervElem = Integer.MAX_VALUE;
//         // 逆向遍历，就是翻转的先序遍历
//         for (int i = postorder.length - 1;i>=0;i--){
//             // 左子树元素必须要小于递增栈被peek访问的元素，否则就不是二叉搜索树
//             if (postorder[i] > pervElem){
//                 return false;
//             }
//             while (!stack.isEmpty() && postorder[i] < stack.peek()){
//                 // 数组元素小于单调栈的元素了，表示往左子树走了，记录下上个根节点
//                 // 找到这个左子树对应的根节点，之前右子树全部弹出，不再记录，因为不可能在往根节点的右子树走了
//                 pervElem = stack.pop();
//             }
//             // 这个新元素入栈
//             stack.push(postorder[i]);
//         }
//         return true;
//     }
// }
