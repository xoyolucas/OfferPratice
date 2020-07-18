// 输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
// 序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

// 示例 1：
// 输入：target = 9
// 输出：[[2,3,4],[4,5]]

// 示例 2：
// 输入：target = 15
// 输出：[[1,2,3,4,5],[4,5,6],[7,8]]

// 限制：
// 1 <= target <= 10^5

#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findContinuousSequence(int target)
    {
        vector<vector<int>> res;

        int i = 1;
        while (target > 0)
        {
            target -= i;
            i++;
            if (target > 0 && target % i == 0)
            {
                vector<int> tmp;
                for (int j = 0; j < i; j++)
                {
                    tmp.push_back(target / i + j);
                }
                res.push_back(tmp);
            }
        }
        reverse(res.begin(), res.end());

        return res;
    }
};