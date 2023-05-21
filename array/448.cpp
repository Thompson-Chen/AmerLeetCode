// 统计数组中的元素
// 找到所有数组中消失的数字
// https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        // 暴力求解会超时
        // for (int i = 1; i <= nums.size(); i++)
        // {   
        //     auto it = find(nums.begin(),nums.end(),i);
        //     if(it != nums.end())
        //     {
        //         // 找到了
        //         continue;
        //     }else{
        //         res.push_back(i);
        //     }
        // }

        // 空间换时间(通过：13.86%/18.21%)
        unordered_map<int,int> mp;
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if(mp.count(nums[i]))
        //     {
        //         mp[nums[i]]++;
        //     }
        //     else
        //     {
        //         mp[nums[i]] = 1;
        //     }
        // }

        // for (int i = 1; i <= nums.size(); i++)
        // {
        //     if(!mp.count(i))
        //     {
        //         res.push_back(i);
        //     }
        // }

        // 更绝，直接把nums当hash表用(通过：40.99%/81.65%)
        int n = nums.size();
        for (auto & num:nums)
        {
            int x = (num-1)%n;
            nums[x] += n;   
        }

        for (int i = 0; i < n; i++)
        {
            if(nums[i] <= n)res.push_back(i+1);
        }
        
        
        
        
        return res;
    }
};

int main()
{
    return 0;
}