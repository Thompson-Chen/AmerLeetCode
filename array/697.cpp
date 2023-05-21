// 统计数组中的元素
// 数组的度
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        // 使用哈希表实现该功能，每一个数映射到一个长度为 333 的数组，
        // 数组中的三个元素分别代表这个数出现的次数、这个数在原数组中第一次出现的位置和这个数在原数组中最后一次出现的位置。
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (mp.count(nums[i]))
            {
                // .count等同于.find
                mp[nums[i]][0]++;
                mp[nums[i]][2] = i;
            }
            else
            {
                mp[nums[i]] = {1,i,i};
            }
        }
        int maxNum = 0, minLen = 0;
        for (auto& vec:mp)
        {
            if (maxNum < vec.second[0]) {
                maxNum = vec.second[0];
                minLen = vec.second[2] - vec.second[1] + 1;
            } else if (maxNum == vec.second[0]) {
                if (minLen > vec.second[2] - vec.second[1] + 1) {
                    minLen = vec.second[2] - vec.second[1] + 1;
                }
            }
        }
        return minLen;
        
    }
};

int main()
{
}