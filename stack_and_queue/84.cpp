// 单调栈
// 柱状图中最大的矩形
// https://leetcode.cn/problems/largest-rectangle-in-histogram/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        // 栈里面去维护一个长方形的高，保持这个单调递增，遇到递减，就出栈然后更新（独立完成！）
        stack<vector<int>> stk;
        int max = 0;
        int rightmost = -1;
        for (int i = 0; i < heights.size(); i++)
        {
            while (!stk.empty() && heights[i] < stk.top()[0])
            {
                vector<int> temp = stk.top();
                stk.pop();
                if (rightmost == -1)
                {
                    rightmost = temp[1];
                }
                int left = stk.empty() ? 0 : stk.top()[1];
                int temp_area = (rightmost - left) * temp[0]; // 计算从当前块到两边的总面积
                max = max > temp_area ? max : temp_area;
            }
            stk.push({heights[i], i});//推入值和下标
            rightmost = -1;
        }

        rightmost = stk.top()[1];
        while (!stk.empty())
        {
            vector<int> temp = stk.top();
            stk.pop();
            int left = stk.empty() ? -1 : stk.top()[1];
            int temp_area = (rightmost - left) * temp[0];
            max = max > temp_area ? max : temp_area;
        }
        return max;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    Solution s = Solution();
    vector<int> vec = {0, 3, 2, 5};
    cout << s.largestRectangleArea(vec);
    return 0;
}
