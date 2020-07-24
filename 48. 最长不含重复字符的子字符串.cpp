// 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

// 示例 1:
// 输入: "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

// 示例 2:
// 输入: "bbbbb"
// 输出: 1
// 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

// 示例 3:
// 输入: "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

// 提示：
// s.length <= 40000

// @lc code=start
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() == 0)
        {
            return 0;
        }
        unordered_set<char> slide_window;
        int max_str = 0;
        int head = 0;
        for (const auto str : s)
        {
            while (slide_window.find(str) != slide_window.end())
            {
                slide_window.erase(s[head]);
                ++head;
            }
            slide_window.insert(str);
            max_str = max(max_str, static_cast<int>(slide_window.size()));
        }
        return max_str;
    }
};
// @lc code=end