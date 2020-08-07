// 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

// 示例 1：
// 输入: n = 3
// 输出: 6

// 示例 2：
// 输入: n = 9
// 输出: 45

// 限制：
// 1 <= n <= 10000

#include <cmath>
using namespace std;

class Solution
{
public:
    int sumNums(int n)
    {
        return (int) (pow(n, 2) + n) >> 1;

        // int res = n;
        // n && (res += sumNums(n - 1)); //不能用if “骤死性评估”，n==0时停止
        // return res;
    }
};