// 哈希表与前缀和
// 和为 K 的子数组
// https://leetcode.cn/problems/subarray-sum-equals-k/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // 方法1：枚举
        // int count = 0;
        // for (int start = 0; start < nums.size(); ++start) {
        //     int sum = 0;
        //     for (int end = start; end >= 0; --end) {
        //         sum += nums[end];
        //         if (sum == k) {
        //             count++;
        //         }
        //     }
        // }
        // return count;

        // 哈希前缀和
        unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto& x:nums) {
            pre += x;
            // 边枚举边查找隐含了“mp中的前缀和一定都在当前x之前”这一条件
            if (mp.find(pre - k) != mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec = {1,2,3};
    Solution s = Solution();
    cout << s.subarraySum(vec, 3) << endl;
    
    return 0;
}
