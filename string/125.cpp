// 回文串的定义
// 验证回文串
// https://leetcode.cn/problems/valid-palindrome/
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // 46.4/23.53
        // 其实还有一种不需要过滤的方法，因为题目并未要求生成过滤字串，直接双指针法
        // 字符串过滤
        // string word=""; // 新字符串
        // for(auto &c:s)
        // {
        //     if((c >= 97 and c <= 122) or (c >= 48 and c <= 57))
        //     {
        //         // 小写
        //         word.push_back(c);
        //     }
        //     else if(c >= 65 and c <= 90)
        //     {
        //         // 大写
        //         word.push_back((char)(c + 32));
        //     }
        // }

        // // 双指针判断回文串
        // int i =0, k = word.length()-1;
        // while(i < k)
        // {
        //     if(word[i] == word[k])
        //     {
        //         i++;
        //         k--;
        //     }else{
        //         return false;
        //     }
        // }

        // return true;

        // 直接上双指针法
        // 100% / 65.64%
        int i = 0, k = s.length();
        while(i < k)
        {
            while (i < k && !isalnum(s[i])) {
                ++i;
            }
            while (i < k && !isalnum(s[k])) {
                --k;
            }
            if (i < k) {
                if (tolower(s[i]) != tolower(s[k])) {
                    return false;
                }
                ++i;
                --k;
            }

        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    string s = "A man, a plan, a canal: Panama";
    Solution solution = Solution();
    solution.isPalindrome(s);
    return 0;
}
