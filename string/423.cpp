// 字符的统计
// 根据字符出现频率排序
// https,//leetcode.cn/problems/sort-characters-by-frequency/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    // 这种贪心法是有问题的，因为有的字母是好几个数字共有的，如"o"，0的优先级并不比1要高
    // string originalDigits(string s)
    // {
    //     int arr[26] = {0};
    //     for (char c : s)
    //     {
    //         arr[c - 'a']++;
    //     }
    //     vector<unordered_map<int, int>> vec;
    //     vec.push_back({{25, 1}, {4, 1}, {17, 1}, {14, 1}});       // 0
    //     vec.push_back({{4, 1}, {14, 1}, {13, 1}});                // 1
    //     vec.push_back({{14, 1}, {19, 1}, {22, 1}});               // 2
    //     vec.push_back({{4, 2}, {17, 1}, {19, 1}, {7, 1}});        // 3
    //     vec.push_back({{17, 1}, {20, 1}, {5, 1}, {14, 1}});       // 4
    //     vec.push_back({{4, 1}, {21, 1}, {5, 1}, {8, 1}});         // 5
    //     vec.push_back({{23, 1}, {18, 1}, {8, 1}});                // 6
    //     vec.push_back({{13, 1}, {21, 1}, {18, 1}, {4, 2}});       // 7
    //     vec.push_back({{19, 1}, {7, 1}, {6, 1}, {4, 1}, {8, 1}}); // 8
    //     vec.push_back({{4, 1}, {13, 2}, {8, 1}});                 // 9
    //     string res = "";
    //     for (int i = 0; i < vec.size(); i++)
    //     {
    //         while (has_num(arr, vec[i]))
    //         {
    //             res += to_string(i);
    //         }
    //     }
    //     return res;
    // }

    // bool has_num(int arr[26], unordered_map<int, int> umap)
    // {
    //     for (auto &item : umap)
    //     {
    //         if (arr[item.first] >= item.second)
    //         {
    //             continue;
    //         }
    //         else
    //         {
    //             return false;
    //         }
    //     }

    //     for (auto &item : umap)
    //     {
    //         arr[item.first] -= item.second;
    //     }

    //     return true;
    // }
    string originalDigits(string s)
    {
        unordered_map<char, int> c;
        for (char ch : s)
        {
            ++c[ch];
        }

        vector<int> cnt(10);
        cnt[0] = c['z'];
        cnt[2] = c['w'];
        cnt[4] = c['u'];
        cnt[6] = c['x'];
        cnt[8] = c['g'];

        cnt[3] = c['h'] - cnt[8];
        cnt[5] = c['f'] - cnt[4];
        cnt[7] = c['s'] - cnt[6];

        cnt[1] = c['o'] - cnt[0] - cnt[2] - cnt[4];

        cnt[9] = c['i'] - cnt[5] - cnt[6] - cnt[8];

        string ans;
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < cnt[i]; ++j)
            {
                ans += char(i + '0');
            }
        }
        return ans;
    }
};
