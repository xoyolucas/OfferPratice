// 给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。
// 请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。

// 示例 1：
// 输入: 2
// 输出: 1
// 解释: 2 = 1 + 1, 1 × 1 = 1

// 示例 2:
// 输入: 10
// 输出: 36
// 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36

// 提示：
// 2 <= n <= 58

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int cuttingRope(int n)
    {
        if (n < 3)
            return 1;
        if (n == 3)
            return 2;
        vector<int> dp(n + 1, 1);
        for (int i = 2; i <= n; i++)
            dp[i] = i;
        for (int i = 4; i <= n; i++)
        {
            for (int j = 1; j <= 4; j++) // j表示剩余绳子长度 ，j>4时，比如5 最大值为2*3=6是一定要剪的，其他大于5的数同理
            {
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
            }
        }
        return dp[n];
    }
};