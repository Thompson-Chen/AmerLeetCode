// 统计数组中的元素
// 错误的集合
// https://leetcode.cn/problems/set-mismatch/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        // 个人想法：先排序后检索
        vector<int> errorNums(2);
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int prev = 0;
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            if (curr == prev) {
                errorNums[0] = prev;
            } else if (curr - prev > 1) {
                errorNums[1] = prev + 1;
            }
            prev = curr;
        }
        if (nums[n - 1] != n) {
            errorNums[1] = n;
        }
        return errorNums;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> v = {1, 3, 2, 2, 4};
    s->findErrorNums(v);
    return 0;
}
