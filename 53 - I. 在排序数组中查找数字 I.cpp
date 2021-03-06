// 统计一个数字在排序数组中出现的次数。

// 示例 1:
// 输入: nums = [5,7,7,8,8,10], target = 8
// 输出: 2

// 示例 2:
// 输入: nums = [5,7,7,8,8,10], target = 6
// 输出: 0

// 限制：
// 0 <= 数组长度 <= 50000

#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // 搜索右边界 right
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] <= target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        int end = left;
        if (right >= 0 && nums[right] != target) // 没找到target
            return 0;

        left = 0;
        // 搜索左边界 right
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        int begin = right;

        return end - begin - 1;
    }
};

// 算法解析：
// 初始化： 左边界 i = 0，右边界 j = len(nums) - 1。
// 循环二分： 当闭区间 [i, j] 无元素时跳出；
// 计算中点 m = (i + j) / 2 （向下取整）；
// 若 nums[m] < target，则 target 在闭区间 [m + 1, j]中，因此执行 i = m + 1；
// 若 nums[m] > target，则 target 在闭区间 [i, m - 1]中，因此执行 j = m - 1；
// 若 nums[m] = target，则右边界 right 在闭区间 [m+1, j]中；左边界 left在闭区间 [i, m-1]中。
// 因此分为以下两种情况：
// 若查找 右边界 right，则执行 i = m + 1；（跳出时 i 指向右边界）
// 若查找 左边界 left，则执行 j = m - 1；（跳出时 j 指向左边界）
// 返回值： 应用两次二分，分别查找 right 和 left ，最终返回 right - left - 1 即可。
