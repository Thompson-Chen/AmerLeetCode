// 数组的旋转
// 轮转数组
// https://leetcode.cn/problems/rotate-array/
#include <iostream>
# include<algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    void reverse(vector<int> &nums, int begin, int end)
    {
        while(begin < end)
        {
            swap(nums[begin],nums[end]);
            begin++;
            end--;
        }
    }
    void rotate(vector<int> &nums, int k)
    {
        // 方法1: 拿额外的数组存储
        // int n = nums.size();
        // k %= n;
        // vector<int> temp_arr(k);
        // for (int i = 0; i < k; i++)
        // {
        //     temp_arr[i] = nums[n - k + i];
        // }
        // for (int i = n - k - 1; i >= 0; i--)
        // {
        //     nums[i + k] = nums[i];
        // }
        // for (int i = 0; i < k; i++)
        // {
        //     nums[i] = temp_arr[i];
        // }

        // 方法2：先翻转全部，再对两部分进行翻转(效率比不过方法1)
        k %= nums.size(); // 3
        // 1,2,3,4,5,6,7
        this->reverse(nums,0,nums.size()-1);// 7,6,5,4,3,2,1
        this->reverse(nums,0,k-1); // 5,6,7,4,3,2,1
        this->reverse(nums,k,nums.size()-1); // 5,6,7,1,2,3,4

        // 方法3: 单变量存储(没太懂意思)
    }
};


int main()
{
    Solution *s = new Solution();
    vector<int> a = {-1,-100,3,99};
    s->rotate(a, 2);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}