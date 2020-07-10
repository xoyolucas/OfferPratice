// 我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

// 示例:
// 输入: n = 10
// 输出: 12
// 解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。

// 说明:  
// 1 是丑数。
// n 不超过1690。

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n == 0)
            return 0;
        vector<int> ugly(n, 0);
        ugly[0] = 1;
        int index1 = 0, index2 = 0, index3 = 0;
        for (int i = 1; i < n; i++)
        {
            int tmp = min(ugly[index1] * 2, min(ugly[index2] * 3, ugly[index3] * 5));
            //可能有相同乘积情况，所以只要是最小的，都要移动指针
            if (ugly[index1] * 2 == tmp)
                index1++;
            if (ugly[index2] * 3 == tmp)
                index2++;
            if (ugly[index3] * 5 == tmp)
                index3++;
            ugly[i] = tmp;
        }

        return ugly[n - 1];
    }
};