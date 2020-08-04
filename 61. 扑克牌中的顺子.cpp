// 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，
// A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

// 示例 1:
// 输入: [1,2,3,4,5]
// 输出: True

// 示例 2:
// 输入: [0,0,1,2,5]
// 输出: True

// 限制：
// 数组长度为 5 
// 数组的数取值为 [0, 13] .

#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool isStraight(vector<int> &nums)
    {
        unordered_set<int> repeat;
        int min_element = 14, max_element = 0;
        for (auto num : nums)
        {
            if (num == 0)
                continue;
            if (repeat.find(num) != repeat.end())
                return false;
            min_element = min(min_element, num);
            max_element = max(max_element, num);
            repeat.insert(num);
        }

        return max_element - min_element < 5;
    }
};