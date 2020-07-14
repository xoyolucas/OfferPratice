// 输入整数数组 arr ，找出其中最小的 k 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，
// 则最小的4个数字是1、2、3、4。

// 示例 1：
// 输入：arr = [3,2,1], k = 2
// 输出：[1,2] 或者 [2,1]

// 示例 2：
// 输入：arr = [0,1,2,1], k = 1
// 输出：[0]

// 限制：
// 0 <= k <= arr.length <= 10000
// 0 <= arr[i] <= 10000

#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> getLeastNumbers(vector<int> &arr, int k)
    {
        vector<int> res;
        if (k == 0)
            return res;

        priority_queue<int> max_heap;
        for (int i = 0; i < k; i++)
        {
            max_heap.push(arr[i]);
        }
        for (int i = k; i < arr.size(); i++)
        {
            if (max_heap.top() > arr[i])
            {
                max_heap.pop();
                max_heap.push(arr[i]);
            }
        }

        for (int i = 0; i < k; i++)
        {
            res.push_back(max_heap.top());
            max_heap.pop();
        }

        return res;
    }
};