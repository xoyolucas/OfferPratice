// 请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和
// pop_front 的均摊时间复杂度都是O(1)。

// 若队列为空，pop_front 和 max_value 需要返回 -1

// 示例 1：
// 输入:
// ["MaxQueue","push_back","push_back","max_value","pop_front","max_value"]
// [[],[1],[2],[],[],[]]
// 输出: [null,null,null,2,1,2]

// 示例 2：
// 输入:
// ["MaxQueue","pop_front","max_value"]
// [[],[],[]]
// 输出: [null,-1,-1]

// 限制：

// 1 <= push_back,pop_front,max_value的总操作数 <= 10000
// 1 <= value <= 10^5

#include <queue>
#include <deque>
using namespace std;

class MaxQueue
{
private:
    queue<int> res;
    deque<int> helper;

public:
    MaxQueue()
    {
    }

    int max_value()
    {
        return helper.empty() ? -1 : helper.front();
    }

    void push_back(int value)
    {
        res.push(value);
        if (helper.empty())
        {
            helper.push_back(value);
            return;
        }
        while (!helper.empty() && value > helper.back())
        {
            helper.pop_back();
        }
        helper.push_back(value);
    }

    int pop_front()
    {
        if (res.empty())
        {
            return -1;
        }

        if (helper.front() == res.front())
        {
            helper.pop_front();
        }

        int num = res.front();
        res.pop();

        return num;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */