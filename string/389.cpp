// 字符的统计
// 字符串中的第一个唯一字符
// https://leetcode.cn/problems/first-unique-character-in-a-string/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        // hash (67.79/5.37)
        unordered_map<char, int> charCount;
        for (char c : s)
        {
            if (charCount.find(c) == charCount.end())
            {
                charCount[c] = 1;
            }
            else
            {
                charCount[c]++;
            }
        }

        for(char c: t)
        {
            if(charCount.find(c) == charCount.end() or charCount[c] == 0)
            {
                return c;
            }
            else
            {
                charCount[c]--;
            }
        }

        return '\0';
    }
};

int main(int argc, char const *argv[])
{
    string s = "a";
    string t = "aa";
    Solution solution = Solution();
    solution.findTheDifference(s,t);
    return 0;
}
