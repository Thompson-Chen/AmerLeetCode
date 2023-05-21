// 数组的遍历
// 三个数的最大乘积
// https://leetcode.cn/problems/maximum-product-of-three-numbers/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int res = 1;
        int temp = INT_MIN;
        int n = nums.size();
        for (int i = n - 1; i >= n - 3; i--)
        {
            res *= nums[i];
        }
        if (nums[0] < 0 and nums[n - 1] > 0)
        {
            temp = nums[0] * nums[1] * nums[n - 1];
            return res > temp ? res : temp;
        }
        return res;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> v = {-100, -98, -1, 2, 3, 4};
    cout << s->maximumProduct(v);

    return 0;
}