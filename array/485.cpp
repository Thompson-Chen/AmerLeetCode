// 数组的遍历
// 最大连续1的个数
// https://leetcode.cn/problems/max-consecutive-ones/
# include <iostream>
# include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // 暴力法 (98.40/18.71)
        int count = 0;
        int max_count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                count++;
            }
            else
            {
                if(count > max_count)
                {
                    max_count = count;
                }
                count = 0;
            }
        }

        if(count > max_count)
        {
            max_count = count;
        }
        return max_count;
    }
};

int main()
{
    vector<int> test_arr = {1,1,0,1,1,1};
    Solution *solution = new Solution();
    cout<< solution->findMaxConsecutiveOnes(test_arr);
    return 0;
}