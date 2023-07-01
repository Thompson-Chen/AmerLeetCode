// 哈希表的查找、插入及删除
// 同构字符串
// https://leetcode.cn/problems/isomorphic-strings/
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        // 双射(96.12/97.51)
        if (s.length() != t.length())
            return false;
        unordered_map<char, char> umap_s2t;
        unordered_map<char, char> umap_t2s;
        for (int i = 0; i < s.length(); i++)
        {
            if (umap_s2t.count(s[i]))
            {
                // 存在双射
                if (umap_s2t.at(s[i]) == t[i])
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                // 因为不同的字符不能映射到同一个字符上
                if(umap_t2s.count(t[i]) and umap_t2s.at(t[i]) != s[i])
                {
                    return false;
                }
                else
                {
                    umap_s2t.emplace(s[i], t[i]);
                    umap_t2s.emplace(t[i], s[i]);
                }
            }
        }
        return true;

        // // 官方题解，更简洁
        // unordered_map<char, char> s2t;
        // unordered_map<char, char> t2s;
        // int len = s.length();
        // for (int i = 0; i < len; ++i) {
        //     char x = s[i], y = t[i];
        //     if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)) {
        //         // 存在映射但映射值不匹配就返回false，否则添加双射
        //         return false;
        //     }
        //     s2t[x] = y;
        //     t2s[y] = x;
        // }
        // return true;

    }
};