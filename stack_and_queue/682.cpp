// 用栈访问最后若干元素
// 棒球比赛
// https://leetcode.cn/problems/basic-calculator-ii/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        // 78.6%/17.21%
        stack<int> scores;
        int pre_1 = 0, pre_2 = 0;
        for (int i = 0; i < operations.size(); i++)
        {
            switch (operations[i][0])
            {
            case '+':
                // 由于保证记录此操作时前面总是存在两个有效的分数，所以不用验证empty
                pre_1 = scores.top();
                scores.pop();
                pre_2 = scores.top();
                scores.emplace(pre_1);
                scores.emplace(pre_1 + pre_2);
                break;
            case 'D':
                // 由于保证记录此操作时前面总是存在一个有效的分数，所以不用验证empty
                scores.emplace(scores.top() * 2);
                break;
            case 'C':
                // 由于保证此操作时前面总是存在一个有效的分数，所以不用验证empty
                scores.pop();
                break;
            default:
                // 数字
                scores.emplace(atoi(operations[i].c_str()));
                break;
            }
        }
        int sum = 0;
        while (!scores.empty())
        {
            sum += scores.top();
            scores.pop();
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> operations = {"5", "2", "C", "D", "+"};
    Solution s = Solution();
    cout << s.calPoints(operations);
    return 0;
}
