// 数字与字符串间转换
// 最小时间差
// https://leetcode.cn/problems/minimum-time-difference/description/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        // 下面是优化
        // 优化之后性能：76.46/10.17
        // 鸽巢原理：如果有 n+1 个或更多的对象要放入 n 个容器中，那么至少有一个容器会包含两个或更多的对象
        // 放在本题中的意思是：一天的分钟节点一共只有24*60 = 1440个，当timePoints长度超过1440时，必然有两个相同的节点，可以直接返回0
        if (timePoints.size() > 1440)
        {
            return 0;
        }
        // 上面是优化

        // 6.21/5.09
        // 先使用sort排序，然后再比较
        sort(timePoints.begin(), timePoints.end());
        vector<int> res;
        int smallest = INT_MAX;
        for (int i = 0; i < timePoints.size(); i++)
        {
            // 使用字符串流 (stringstream) 分割时间字符串
            stringstream ss(timePoints[i]);
            string token;
            getline(ss, token, ':');   // 使用冒号 ':' 分割小时和分钟部分
            int hours = stoi(token);   // 将小时部分转换为整数
            getline(ss, token);        // 获取分钟部分
            int minutes = stoi(token); // 将分钟部分转换为整数
            // 计算总分钟数
            int totalMinutes = hours * 60 + minutes;
            if(res.size() > 0)
            {
                int diff = totalMinutes - res[res.size() - 1];
                smallest = smallest > diff ? diff : smallest;
            }
            res.push_back(totalMinutes);
        }
        smallest = smallest > res[0] + 1440 - res[res.size() - 1] ? res[0] + 1440 - res[res.size() - 1] : smallest;
        return smallest;
    }
};