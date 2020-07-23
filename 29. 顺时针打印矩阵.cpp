// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

// 示例 1：
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]

// 示例 2：
// 输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// 输出：[1,2,3,4,8,12,11,10,9,5,6,7]

// 限制：
// 0 <= matrix.length <= 100
// 0 <= matrix[i].length <= 100

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> res;
        if (matrix.empty())
        {
            return res;
        }

        //赋值上下左右边界
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (true)
        {
            for (int i = left; i <= right; ++i)
            {
                res.push_back(matrix[top][i]); //从左到右移动
            }
            if (++top > bottom) //重新设定上边界
                break;

            for (int i = top; i <= bottom; ++i)
            {
                res.push_back(matrix[i][right]); //向上往下移动
            }
            if (--right < left)
                break;

            for (int i = right; i >= left; --i)
            {
                res.push_back(matrix[bottom][i]); //从右向左移动
            }
            if (--bottom < top)
                break;

            for (int i = bottom; i >= top; --i)
            {
                res.push_back(matrix[i][left]); //向下往上移动
            }
            if (++left > right)
                break;
        }
        return res;
    }
};