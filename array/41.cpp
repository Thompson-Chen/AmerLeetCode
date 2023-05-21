// 统计数组中的元素
// 缺失的第一个正数
// https://leetcode.cn/problems/first-missing-positive/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        // 独立没想出来：原地哈希（因为要求时间复杂度是O（n），空间复杂度是O（1））
        // 关键思想：缺失的正整数一定在[1,n+1]的范围里——因此可以将原数组当成哈希表
        // 如果对应元素存在，则转为负数，返回第一个正数所在的位置，即为缺失的正数

        // 把所有不在[1,n+1]范围内的数全部标为1，如果扫了一遍，1不存在，则直接返回1
        // 43.41/25.25
        int n = nums.size();
        bool has_one = false;
        for (int i = 0; i < n; i++)
        {
            if (!has_one && nums[i] == 1)
            {
                has_one = true;
            }
            if (nums[i] <= 0 || nums[i] > n)
            {
                nums[i] = 1;
            }
        }

        if (!has_one)
        {
            return 1;
        }

        // 若到此处还没return，说明1是存在的
        // 若存在某个正数，则将对应位置的元素变为负数
        for (int i = 0; i < n; i++)
        {
            nums[abs(nums[i]) - 1] = -abs(nums[abs(nums[i]) - 1]);
        }
        // 开始遍历
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                return i + 1;
            }
        }

        return n + 1;
    }
};

int main()
{
    vector<int> arr = {3,1};
    Solution *s = new Solution();
    cout << s->firstMissingPositive(arr);

    return 0;
}