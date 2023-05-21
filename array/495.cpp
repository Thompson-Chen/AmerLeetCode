// 数组的遍历
// 提莫攻击
// https://leetcode.cn/problems/teemo-attacking/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        // 遍历一遍即可
        int totalCount = duration;
        for (int i = 0; i < timeSeries.size() - 1; i++)
        {
            int temp = timeSeries[i + 1] - timeSeries[i];
            if (temp >= duration)
            {
                totalCount += duration;
            }
            else
            {
                totalCount += temp;
            }
        }

        return totalCount;
    }
};

int main()
{
    return 0;
}