// 字符
// 检测大写字母
// https://leetcode.cn/circle/discuss/E3yavq/
#include <iostream>
using namespace std;

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        // 简单题，ASCII的应用
        // 100%/38.30%
        int word_len = word.length();
        if (word_len > 1)
        {
            // 看首字母是大写还是小写
            if (word[0] >= 97 and word[0] <= 122)
            {
                // 首字母小写
                for (int i = 1; i < word_len; i++)
                {
                    if (word[i] >= 65 and word[i] <= 90)
                    {
                        return false;
                    }
                }
            }
            else
            {
                // 首字母大写
                // 看第二个字母是大写还是小写
                if (word[1] >= 97 and word[1] <= 122)
                {
                    // 第二个字母小写
                    for (int i = 2; i < word_len; i++)
                    {
                        if (word[i] >= 65 and word[i] <= 90)
                        {
                            return false;
                        }
                    }
                }
                else
                {
                    // 第二个字母大写
                    for (int i = 2; i < word_len; i++)
                    {
                        if (word[i] >= 97 and word[i] <= 122)
                        {
                            return false;
                        }
                    }
                }
            }
            return true;
        }
        else
        {
            return true;
        }
    }
};