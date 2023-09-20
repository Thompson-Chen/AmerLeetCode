// 数字与字符串间转换
// 外观数列
// https://leetcode.cn/problems/count-and-say/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        // 12.31/10.79
        string res[30];
        res[0] = "1";
        res[1] = "11";
        for (int i = 2; i < 30; i++)
        {
            int count = 1;
            string s = "";
            for (int j = 0; j < res[i - 1].length(); j++)
            {
                if (j == res[i - 1].length() - 1)
                {
                    if (res[i - 1][res[i - 1].length() - 1] != res[i - 1][res[i - 1].length() - 2])
                    {
                        s += "1";
                        s.push_back(res[i - 1][res[i - 1].length() - 1]);
                        count = 1;
                    }
                    else if (count > 1)
                    {
                        s += to_string(count);
                        s.push_back(res[i - 1][j]);
                        count = 1;
                    }
                }
                else if (res[i - 1][j] == res[i - 1][j + 1])
                {
                    count++;
                }
                else
                {
                    s += to_string(count);
                    s.push_back(res[i - 1][j]);
                    count = 1;
                }
            }
            res[i] = s;
        }
        return res[n - 1];
    }
};

int main(int argc, char const *argv[])
{
    Solution solution = Solution();
    int n = 4;
    cout << solution.countAndSay(n);
    return 0;
}

// 官方题解，思路是一样的，但是代码更简洁
// class Solution {
// public:
//     string countAndSay(int n) {
//         string prev = "1";
//         for (int i = 2; i <= n; ++i) {
//             string curr = "";
//             int start = 0;
//             int pos = 0;

//             while (pos < prev.size()) {
//                 while (pos < prev.size() && prev[pos] == prev[start]) {
//                     pos++;
//                 }
//                 curr += to_string(pos - start) + prev[start];
//                 start = pos;
//             }
//             prev = curr;
//         }
        
//         return prev;
//     }
// };

// 作者：力扣官方题解
// 链接：https://leetcode.cn/problems/count-and-say/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。