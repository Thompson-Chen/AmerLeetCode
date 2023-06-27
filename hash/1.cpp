// 哈希表与索引
// 两数之和
// https://leetcode.cn/problems/two-sum/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 91.89/56.47
        // 只会存在一个有效答案
        unordered_map<int,int> umap;
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            if(umap.find(target-nums[i]) != umap.end())
            {
                res.push_back(umap[target-nums[i]]);
                res.push_back(i);
                break;
            }
            umap.emplace(nums[i], i);
        }

        return res;
    }
};

int main()
{
    return 0;
}