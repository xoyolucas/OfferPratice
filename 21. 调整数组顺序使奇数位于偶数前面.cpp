// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，
// 所有偶数位于数组的后半部分。

// 示例：
// 输入：nums = [1,2,3,4]
// 输出：[1,3,2,4]
// 注：[3,1,2,4] 也是正确的答案之一。

// 提示：
// 1 <= nums.length <= 50000
// 1 <= nums[i] <= 10000

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right)
        {
            if (nums[left] % 2 == 1)
            {
                left++;
            }
            else
            {
                int tmp = nums[right];
                nums[right] = nums[left];
                nums[left] = tmp;
                right--;
            }
        }

        return nums;
    }
};