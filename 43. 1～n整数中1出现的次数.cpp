// 输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。

// 例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。

// 示例 1：
// 输入：n = 12
// 输出：5

// 示例 2：
// 输入：n = 13
// 输出：6

// 限制：
// 1 <= n < 2^31

#include <cmath>

class Solution
{
public:
    int countDigitOne(int n)
    {
        int low = 0, high = n / 10, cur = n % 10;
        int times = 0;
        int count = 0;
        while (n != 0)
        {
            if (cur == 0)
            {
                count += high * pow(10, times);
            }
            else if (cur == 1)
            {
                count += high * pow(10, times) + low + 1;
            }
            else
            {
                count += (high + 1) * pow(10, times);
            }
            low = cur * pow(10, times) + low;
            n /= 10;
            cur = n % 10;
            high = n / 10;
            times++;
        }

        return count;
    }
};