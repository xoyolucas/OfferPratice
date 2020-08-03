// 把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。
// 你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

// 示例 1:
// 输入: 1
// 输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]

// 示例 2:
// 输入: 2
// 输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]

// 限制：
// 1 <= n <= 11

#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    vector<double> twoSum(int n)
    {
        vector<double> dp(6 * n);
        for (int i = 0; i < 6; i++)
        {
            dp[i] = 1;
        }

        int time = 1;
        while (time++ < n)
        {
            for (int i = 6 * time - 1; i >= time - 1; i--)
            {
                dp[i] = 0; // 置0
                for (int j = 1; j <= 6; j++)
                {
                    if (i - j < time - 2)
                    {
                        break;
                    }
                    dp[i] += dp[i - j];
                }
            }
        }

        double total = pow(6, n);
        vector<double> res(dp.begin() + n - 1, dp.end());
        for (auto &num : res)
        {
            num /= total;
        }

        return res;
    }
};