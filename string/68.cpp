// 文本左右对齐
// 字符串变换
// https://leetcode.cn/problems/text-justification/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        // 思路：利用队列和临时变量记录每行的长度
        queue<string> q;
        int len_cnt = 0;
        vector<string> ans;
        for (int i = 0; i < words.size(); i++)
        {   
            int temp_blk_num = q.size() > 1? q.size() - 1: 0;
            if (len_cnt + temp_blk_num+1 + words[i].length() <= maxWidth)
            {
                len_cnt += words[i].length();
                q.push(words[i]);
            }
            else
            {
                // 开始拼接
                // 获取空格数
                int avg_block = 0, ext_block = 0;
                bool only_one = false;
                if (q.size() > 1)
                {
                    avg_block = (maxWidth - len_cnt) / (q.size() - 1);
                    ext_block = (maxWidth - len_cnt) % (q.size() - 1);
                }
                else
                {
                    only_one = true;
                }
                string s = "";

                while (!q.empty())
                {
                    int n = (ext_block-- > 0) ? avg_block + 1 : avg_block;
                    if (only_one)
                    {
                        n = maxWidth - len_cnt;
                    }
                    else if(q.size() == 1)
                    {
                        n = 0;
                    }
                    string block(n, ' ');
                    s += q.front() + block;
                    q.pop();
                }
                len_cnt = 0;
                i--;
                ans.push_back(s);
            }
        }

        string s = "";

        while (!q.empty())
        {

            s += q.size() > 1 ? q.front() + " " : q.front();
            q.pop();
        }
        if (s.length() < maxWidth)
        {
            string blk(maxWidth - s.length(), ' ');
            s += blk;
        }
        ans.push_back(s);
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution = Solution();
    vector<string> vec = {"What","must","be","acknowledgment","shall","be"};
    vector<string> res = solution.fullJustify(vec,16);

    return 0;
}
