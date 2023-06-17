// 哈希表的查找、插入及删除
// 存在重复元素
// https://leetcode.cn/problems/contains-duplicate/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // 法1：排序逐个遍历
        // sort(nums.begin(), nums.end());
        // for(int i = 0; i < nums.size()-1;i++)
        // {
        //     if(nums[i] == nums[i+1])
        //     {
        //         return true;
        //     }
        // }
        // return false;

        // 法2：哈希表
        unordered_set<int> s;
        for(int x: nums)
        {
            if (s.find(x) != s.end()){
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};