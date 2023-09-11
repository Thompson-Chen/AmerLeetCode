// 字符的统计
// 根据字符出现频率排序
// https://leetcode.cn/problems/sort-characters-by-frequency/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        // 使用hash+最大堆
        // 64.41/34.09
        unordered_map<char, int> hash;
        for (char c : s)
        {
            hash[c]++;
        }
        priority_queue<pair<int, char>> queue;
        for (auto &item : hash)
        {
            queue.emplace(item.second, item.first);
        }
        string res = "";
        while (!queue.empty())
        {
            char c = queue.top().second;
            int n = queue.top().first;
            for (int i = 0; i < n; i++)
            {
                res += c;
            }
            queue.pop();
        }
        return res;
    }
};