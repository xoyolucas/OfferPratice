// 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，
// 25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

// 示例 1:
// 输入: 12258
// 输出: 5
// 解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"

// 提示：
// 0 <= num < 231
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int translateNum(int num)
    {
        string str = to_string(num);
        vector<int> dp(3, 1);
        if (str.empty())
            return 0;
        if (str.size() == 1)
            return 1;

        for (int i = 1; i < str.size(); i++)
        {
            string tmp = str.substr(i - 1, 2);
            if (tmp >= "10" && tmp <= "25")
            {
                dp[2] = dp[0] + dp[1];
            }
            else
            {
                dp[2] = dp[1];
            }
            dp[0] = dp[1];
            dp[1] = dp[2];
        }

        return dp[2];
    }
};