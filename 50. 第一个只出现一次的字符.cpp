// 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。

// 示例:
// s = "abaccdeff"
// 返回 "b"

// s = ""
// 返回 " "

// 限制：
// 0 <= s 的长度 <= 50000

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    char firstUniqChar(string s)
    {
        if (s.empty())
            return ' ';

        vector<int> dict(26, 0);
        for (auto c : s)
        {
            dict[c - 'a'] += 1;
        }

        for (auto c : s)
        {
            int index=c-'a';
            if (dict[index] == 1)
            {
                return 'a' + index;
            }
        }

        return ' ';
    }
};