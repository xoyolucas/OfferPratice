// 给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。

// 示例:
// 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
// 输出: [3,3,5,5,6,7]
// 解释:

//   滑动窗口的位置                最大值
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7

// 提示：
// 你可以假设 k 总是有效的，在输入数组不为空的情况下，1 ≤ k ≤ 输入数组的大小。

#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        if (nums.empty())
            return res;

        deque<int> max_queue;
        for (int i = 0; i < k; i++)
        {
            while (!max_queue.empty() && nums[i] > max_queue.back())
            {
                max_queue.pop_back();
            }
            max_queue.push_back(nums[i]);
        }
        res.push_back(max_queue.front());

        for (int i = k; i < nums.size(); i++)
        {
            if (max_queue.front() == nums[i - k])
            {
                max_queue.pop_front();
            }
            while (!max_queue.empty() && nums[i] > max_queue.back())
            {
                max_queue.pop_back();
            }
            max_queue.push_back(nums[i]);
            res.push_back(max_queue.front());
        }

        return res;
    }
};