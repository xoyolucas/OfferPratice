// 数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
// 输入一个数组，求出这个数组中的逆序对的总数。

// 示例 1:
// 输入: [7,5,6,4]
// 输出: 5

// 限制：
// 0 <= 数组长度 <= 50000

#include <vector>
using namespace std;

class Solution
{
public:
    int reversePairs(vector<int> &nums)
    {
        vector<int> tmp(nums.size(), 0);
        return mergeSort(nums, 0, nums.size() - 1, tmp);
    }

    int mergeSort(vector<int> &nums, int left, int right, vector<int> &tmp)
    {
        if (left >= right)
            return 0;

        int mid = (left + right) / 2;
        int count_left = mergeSort(nums, left, mid, tmp);
        int count_right = mergeSort(nums, mid + 1, right, tmp);

        if (nums[mid] <= nums[mid + 1]) // 右侧必定大于左侧
        {
            return count_left + count_right;
        }

        return merge(nums, left, mid, right, tmp) + count_left + count_right;
    }

    int merge(vector<int> &nums, int left, int mid, int right, vector<int> &tmp)
    {
        for (int i = left; i <= right; i++)
        {
            tmp[i] = nums[i];
        }

        int p = left;
        int q = mid + 1;
        int count = 0;
        for (int i = left; i <= right; i++)
        {
            if (p == mid + 1)
            {
                nums[i] = tmp[q];
                q++;
            }
            else if (q == right + 1)
            {
                nums[i] = tmp[p];
                p++;
            }
            else if (tmp[p] <= tmp[q])
            {
                nums[i] = tmp[p];
                p++;
            }
            else
            {
                nums[i] = tmp[q];
                q++;
                count += mid - p + 1; //右侧元素q小于左侧元素的个数
            }
        }

        return count;
    }
};