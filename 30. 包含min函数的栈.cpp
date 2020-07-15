// 定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，
// 调用 min、push 及 pop 的时间复杂度都是 O(1)。

// 示例:
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.min();   --> 返回 -3.
// minStack.pop();
// minStack.top();      --> 返回 0.
// minStack.min();   --> 返回 -2.

// 提示：
// 各函数的调用总次数不超过 20000 次
#include <stack>
using namespace std;

class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        a.push(x);
        if (b.empty() || x <= b.top())
        {
            b.push(x);
        }
    }

    void pop()
    {
        if (a.top() == b.top())
        {
            b.pop();
        }
        a.pop();
    }

    int top()
    {
        return a.top();
    }

    int min()
    {
        return b.top();
    }

private:
    stack<int> a;
    stack<int> b;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */