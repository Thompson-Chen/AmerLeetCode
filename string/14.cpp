// 公共前缀
// 最长公共前缀
// https://leetcode.cn/problems/longest-common-prefix/description/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        // // 纵向遍历（最符合人类常规思维的方法，就是依次遍历每个字符串的对应字符(100%/68.75%)
        // if (!strs.size())
        // {
        //     return "";
        // }
        // int length = strs[0].size();
        // int count = strs.size();
        // for (int i = 0; i < length; i++)
        // {
        //     char c = strs[0][i];
        //     for (int j = 1; j < count; j++)
        //     {
        //         if (i == strs[j].size() || strs[j][i] != c)
        //         {
        //             return strs[0].substr(0, i);
        //         }
        //     }
        // }
        // return strs[0];

        // 横向遍历，一个字符串一个字符串完整地看过去
        // 分治法
        // 二分查找法（公共前缀的长度一定不会超过字符串数组中长度最短的元素）

    }
};