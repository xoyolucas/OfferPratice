// 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
// 例如，字符串"+100"、"5e2"、"-123"、"3.1416"、"0123"都表示数值，
// 但"12e"、"1a3.14"、"1.2.3"、"+-5"、"-1E-16"及"12e+5.4"都不是。

// 有限状态机
#include <string>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    bool isNumber(string s)
    {
        vector<unordered_map<char, int>> states;
        unordered_map<char, int> tmp;

        // s代表sign，正负号
        // d代表digit，数字
        // 所有表之外的状态转移即为非法数字

        // 0，头部空格状态
        tmp[' '] = 0; // 输入 空格 还是 空格状态0
        tmp['s'] = 1; // 输入 正负号 进入 符号状态1
        tmp['d'] = 2; // 输入 数字 进入 小数点前数字状态2
        tmp['.'] = 4; // 输入 小数点 进入 前为空小数点后首位数字状态4
        states.push_back(tmp);
        tmp.clear();
        // 1，符号状态
        tmp['d'] = 2; // 输入 数字 进入 小数点前的数字状态2
        tmp['.'] = 4; // 输入小数点 进入 前为空小数点后首位数字状态4
        states.push_back(tmp);
        tmp.clear();
        // 2，小数点前数字状态
        tmp['d'] = 2; // 输入 数字 还是 小数点前的数字状态2
        tmp['.'] = 3; // 输入 小数点 进入 前非空小数点后的数字状态3
        tmp['e'] = 5; // 输入 e 进入 指数符号状态5
        tmp[' '] = 8; // 输入 空格 进入 尾部空格状态8
        states.push_back(tmp);
        tmp.clear();
        // 3，前非空小数点后的数字状态
        tmp['d'] = 3; // 输入 数字 还是 前非空小数点后的数字状态3
        tmp['e'] = 5; // 输入 e 进入 指数符号状态5
        tmp[' '] = 8; // 输入 空格 进入尾部空格状态8
        states.push_back(tmp);
        tmp.clear();
        // 4，前为空小数点后首位数字状态4
        tmp['d'] = 3; // 输入 数字 进入 前非空小数点后的数字状态3
        states.push_back(tmp);
        tmp.clear();
        // 5，指数符号状态5
        tmp['s'] = 6; // 输入 正负号 进入 指数后的符号状态6
        tmp['d'] = 7; // 输入 数字 进入 指数位置数字状态7
        states.push_back(tmp);
        tmp.clear();
        // 6，指数后的符号状态
        tmp['d'] = 7; // 输入 数字 进入 指数位置数字状态7
        states.push_back(tmp);
        tmp.clear();
        // 7，指数位置数字状态
        tmp['d'] = 7; // 输入 数字 还是 指数位置数字状态7
        tmp[' '] = 8; // 输入 空格 进入 尾部空格状态8
        states.push_back(tmp);
        tmp.clear();
        // 8，尾部空格状态
        tmp[' '] = 8; // 输入 空格 还是 尾部空格状态8
        states.push_back(tmp);
        tmp.clear();

        // 初始状态，在0状态
        int p = 0;
        // 状态转移的输入key
        char t;
        // 逐字符
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            // 如果是数字，key='d'
            if (c >= '0' && c <= '9')
            {
                t = 'd';
            }
            // 如果是正负号，key='s'
            else if (c == '+' || c == '-')
            {
                t = 's';
            }
            // 如果是其他字符，key='c'，包含了'.' ' ' 其他非法字符
            else
            {
                t = c;
            }
            auto it = states[p].find(t);
            // 如果找不到这个状态转移，则非法数字
            if (it == states[p].end())
            {
                return false;
            }
            // 如果找到，获取转移后的状态
            p = it->second;
        }
        // 是否在允许结尾的状态2 3 7 8
        return p == 2 || p == 3 || p == 7 || p == 8;
    }
};