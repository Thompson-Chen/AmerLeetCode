// 统计数组中的元素
// 数组中重复的元素
// https://leetcode.cn/problems/find-all-duplicates-in-an-array/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // 要求：时间复杂度O(n)，使用常量额外空间的算法
        // 参考题448的解法，直接在原数组上进行操作(通过：98.99/68.97)
        int n = nums.size();
        vector<int> res;
        for(auto & num: nums)
        {
            int x = (num-1)%n;
            nums[x] += n;
        }
        
        int temp = 2*n;
        for (int i = 0; i < n; i++)
        {
            if(nums[i]> temp)res.push_back(i+1);
        }
        return res;
    }
};


int main()
{

}