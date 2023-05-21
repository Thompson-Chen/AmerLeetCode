// 数组的遍历
// 第三大的数
// https://leetcode.cn/problems/third-maximum-number/
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        // 利用数据结构：有序集合 set
        set<int> s;
        for (int num : nums)
        {
            s.insert(num);
            if (s.size() > 3)
            {
                s.erase(s.begin());
            }
        }

        return s.size() == 3 ? *s.begin() : *s.rbegin();

        // // 一次遍历
        // long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;
        // bool has_third = false;

        // for (long i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] > first)
        //     {
        //         third = second;
        //         second = first;
        //         first = nums[i];
        //     }
        //     else if (first > nums[i] and nums[i] > second)
        //     {
        //         third = second;
        //         second = nums[i];
        //     }
        //     else if (second > nums[i] and nums[i] > third)
        //     {
        //         third = nums[i];
        //     }
        // }

        // return third == LONG_MIN ? first : third;
    }
};

int main()
{
}