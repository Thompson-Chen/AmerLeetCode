//
//
//
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {

        // // 方法1：单调栈 + 哈希表 5.56%/5.01%
        // vector<int> res(temperatures.size(), 0);
        // stack<vector<int>> stk;
        // for (int i = temperatures.size() - 1; i >= 0; i--)
        // {
        //     while (!stk.empty() && temperatures[i] >= stk.top()[0])
        //     {
        //         stk.pop();
        //     }
        //     res[i] = stk.empty() ? 0 : (stk.top()[1] - i);
        //     stk.push({temperatures[i],i});
        // }

        // return res;

        // 方法2：基于方法1的优化——实际上栈中不用同时存储<值，下标>，直接存下标就好了，因为值可以通过下标在数组中去访问
        // 24.57%/86.59%
        vector<int> res(temperatures.size(), 0);
        stack<int> stk;
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            while(!stk.empty() && temperatures[i] >= temperatures[stk.top()])
            {
                stk.pop();
            }
            res[i] = stk.empty() ? 0 : (stk.top() - i);
            stk.push(i);
        }
        return res;
    }
};