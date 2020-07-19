// 输入一个字符串，打印出该字符串中字符的所有排列。

// 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。

// 示例:
// 输入：s = "abc"
// 输出：["abc","acb","bac","bca","cab","cba"]

// 限制：
// 1 <= s 的长度 <= 8

#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
private:
    vector<string> res;

public:
    vector<string> permutation(string s)
    {
        dfs(s, 0);
        return res;
    }

    void dfs(string &s, int index)
    {
        if (index == s.size() - 1)
        {
            res.push_back(s);
            return;
        }
        unordered_set<char> tmp;
        for (int i = index; i < s.size(); i++)
        {
            if (tmp.find(s[i]) != tmp.end())
            {
                continue;
            }
            tmp.insert(s[i]);
            swap(s, index, i);
            dfs(s, index + 1);
            swap(s, i, index);
        }
    }

    void swap(string &s, int i, int j)
    {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
};