// 哈希表与前缀和
// 连续数组
// https://leetcode.cn/problems/contiguous-array/
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return 0;
        }
        // 枚举(设置几个可以提前退出的条件) [不出意外地超时了：563个测试用例只通过了30个]
        // for (int i = 1; i < nums.size(); i++)
        // {
        //     nums[i] += nums[i - 1];
        // }
        // int max = 0; // 符合条件的最大长度
        // for (int j = nums.size() - 1; j >= 1; j--)
        // {
        //     if (j + 1 == nums[j] * 2)
        //     {
        //         max = max < j + 1 ? j + 1 : max;
        //         continue;
        //     }
        //     for (int i = 0; i < j - 1; i++)
        //     {
        //         if (j - i == (nums[j] - nums[i]) * 2)
        //         {
        //             max = max < j - i ? j - i : max;
        //             break;
        //         }
        //     }
        // }

        // return max;

        // 参考官方题解：hash优化（如果要优化的话就不能将0视为0，而是要把0视为-1）
        // 当前缀和为0的时候，说明0和1的数量相等
        int counter = 0;
        unordered_map<int,int> umap; // key为前缀和，value为前缀和第一次出现的下标
        umap[0] = -1; // 考虑nums[-1]的情况
        int max = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                counter++;
            }
            else
            {
                counter--;
            }

            if(umap.count(counter))
            {
                int preIndex = umap[counter];
                max = i - preIndex > max ? i - preIndex : max;
            }
            else
            {
                umap[counter] = i;
            }
        }
        return max;
    }
};

int main()
{
    vector<int> vec = {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1};
    Solution s = Solution();
    cout<< s.findMaxLength(vec);
    return 0;
}