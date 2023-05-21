// 数组的改变/移动
// 最小操作次数使数组元素相等
// https://leetcode.cn/problems/minimum-moves-to-equal-array-elements/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        // 这道题说要每轮同时对n-1个数加1直到所有数相同
        // 我们可以转换为每轮对1个数减1直到所有数相同，这样更为简单！！（不排序找最小值的方法更快！）
        // sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 1)
            return 0;
        int min_num = nums[0];
        for (int i = 0; i < n; i++)
        {
            min_num = min_num > nums[i]? nums[i]:min_num;
        }
        
        int diff = 0;
        for (int i = 0; i < n; i++)
        {
            diff += nums[i] - min_num;
        }

        return diff;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> nums = {1, 1, 1};
    cout << s->minMoves(nums) << endl;

    return 0;
}