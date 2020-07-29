// 数字以0123456789101112131415…的格式序列化到一个字符序列中。
// 在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，等等。

// 请写一个函数，求任意第n位对应的数字。

// 示例 1：
// 输入：n = 3
// 输出：3

// 示例 2：
// 输入：n = 11
// 输出：0

// 限制：
// 0 <= n < 2^31
#include <string>
using namespace std;

class Solution
{
public:
    int findNthDigit(int n)
    {
        int digit = 1;
        long start = 1;
        long total = 9;
        while (n > total)
        {
            n -= total;
            start *= 10;
            digit++;
            total += 9 * start * digit;
        }
        long num = start + (n - 1) / digit;
        char res = to_string(num)[(n - 1) % digit];
        return res - '0';
    }
};