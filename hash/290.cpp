// 哈希表的查找、插入及删除
// 单词规律
// https://leetcode.cn/problems/word-pattern/
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        // 100%/90.84%
        unordered_map<char, string> char2str;
        unordered_map<string, char> str2char;
        int len = s.length();
        int start = 0;
        int end = 0;
        int i = 0, j = 0;
        for (auto ch : pattern)
        {
            i++;
            end = start;
            while (end < len and s[end] != ' ')
                end++;
            if (end > start)
                j++;
            if (i != j)
            {
                return false;
            }
            string temp = s.substr(start, end - start);
            if (char2str.count(ch) == 0 and str2char.count(temp) == 0)
            {
                // 之前没见过该“双射”
                char2str[ch] = temp;
                str2char[temp] = ch;
            }
            else if (char2str.count(ch) == 1 and str2char.count(temp) == 1 and char2str[ch] == temp and str2char[temp] == ch)
            {
                // 存在该双射
            }
            else
            {
                return false;
            }
            start = end + 1;
        }

        if (end != len)
            return false;
        return true;
    }
};

int main()
{
    // // unordered_map的基本用法
    // unordered_map<string, string> mp;
    // mp.emplace("1", "what happened!");
    // mp.emplace("2", "nothing happened!");
    // mp.emplace("1", "sorry!"); // 不会报错，但是也不会插入
    // mp["1"] = "sorry";         // 重载了 [] 运算符，其功能是可以向访问数组中元素那样，只要给定某个键值对的键 key，就可以获取该键对应的值。注意，如果当前容器中没有以 key 为键的键值对，则其会使用该键向当前容器中插入一个新键值对。若存在该键则对value进行修改；
    // for (auto iter = mp.begin(); iter != mp.end(); ++iter)
    // {
    //     cout << iter->first << " " << iter->second << endl;
    // }
    Solution s = Solution();
    cout << s.wordPattern("jquery", "jquery");
    return 0;
}