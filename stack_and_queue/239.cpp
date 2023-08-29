// 滑动窗口最大值问题
// 滑动窗口最大值
// https://leetcode.cn/problems/sliding-window-maximum/description/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <string>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        // 优先队列，其中元素为(元素值，元素下标)
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; i++)
        {
            q.emplace(nums[i], i);
        }

        vector<int> result = {q.top().first};
        for (int i = k; i < nums.size(); i++)
        {
            q.emplace(nums[i], i);
            while (i - q.top().second >= k) 
            {
                q.pop();
            }
            result.push_back(q.top().first);
        }

        return result;
    }
};
