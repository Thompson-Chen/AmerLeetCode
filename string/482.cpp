// 密钥格式化
// 字符串变换
// https://leetcode.cn/problems/license-key-formatting/description/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution
{
public:
    string licenseKeyFormatting(string s, int k)
    {
        string ans = "";
        int cnt = 0;
        for (int i = s.length()-1; i >= 0; i--)
        {
            if (s[i] == '-')
            {
                continue;
            }
            else
            {
                cnt++;
                s[i] = isalpha(s[i]) ? toupper(s[i]) : s[i];
                ans = s[i] + ans;
                if (cnt == k)
                {
                    cnt = 0;
                    ans = "-" + ans;
                }
            }
        }
        return ans[0] =='-'?ans.substr(1,ans.length()-1):ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution = Solution();
    string s = "--a-a-a-a--";
    cout << solution.licenseKeyFormatting(s,2) << endl;
    return 0;
}

// 不知道为什么会超时，其实思路都是一样的
// 下面是官方题解
// class Solution {
// public:
//     string licenseKeyFormatting(string s, int k) {
//         string ans;
//         int cnt = 0;
        
//         for (int i = s.size() - 1; i >= 0; i--) {
//             if (s[i] != '-') {
//                 ans.push_back(toupper(s[i]));
//                 cnt++;
//                 if (cnt % k == 0) {
//                     ans.push_back('-');
//                 }  
//             }
//         }
//         if (ans.size() > 0 && ans.back() == '-') {
//             ans.pop_back();
//         }
//         reverse(ans.begin(), ans.end());
        
//         return ans;
//     }
// };

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/license-key-formatting/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
