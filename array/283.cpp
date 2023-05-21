// 数组的改变/移动
// 移动零(必须在不复制数组的情况下原地对数组进行操作）
// https://leetcode.cn/problems/move-zeroes/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    // 移位操作：将nums[i]移到数组的最后
    void shift(vector<int> &nums, int i)
    {
        int n = nums.size();
        int temp = nums[i];
        for (int j = i + 1; j < n; j++)
        {
            nums[j - 1] = nums[j];
        }
        nums[n - 1] = temp;
    }

    void moveZeroes(vector<int> &nums)
    {
        // 暴力法：遍历
        // int len = nums.size();
        // for (int i = 0; i < len; i++)
        // {
        //     if (nums[i] == 0)
        //     {
        //         this->shift(nums, i);
        //         i--;
        //         len--;
        //     }
        // }

        // 双指针法
        // int n = nums.size();
        // int left = 0;
        // int right = 0;
        // while(right < n)
        // {
        //     if(nums[right])
        //     {
        //         // 只要right指向的内容为非零值，则左右指针内容进行交换，同时左指针右移
        //         swap(nums[left], nums[right]);
        //         left++;
        //     }
        //     right++;
        // }
        // 直接从数组下标入手
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {count++;continue;}
            nums[i - count] = nums[i];
        }
        while (count>0){
            nums[nums.size()-count]=0;
            count--;
        }
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> v = {0,0,1};
    s->moveZeroes(v);
    for (int i = 0; i < v.size(); i++)
    {
        cout<< v[i]<<" ";
    }
    
}