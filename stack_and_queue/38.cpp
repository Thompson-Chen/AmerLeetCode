// 用栈访问最后若干元素
// 文件的最长绝对路径
// https://leetcode.cn/problems/longest-absolute-file-path/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

class Solution
{
public:
    int lengthLongestPath(string input)
    {
        // 34.69%/91.02%
        // 栈结构存储目录/文件长度
        int res = 0;      // 只有当遇到文件才更新
        int temp_res = 0; // 实时更新
        int temp_len = 0;
        bool is_file = false; // 判断是否是文件
        int level = 0;        // 根据/t的个数判断级数
        stack<int> paths;

        for (int i = 0; i < input.length(); i++)
        {
            switch (input[i])
            {
            case '\n':
                // 出栈入栈操作
                while (paths.size() > level)
                {
                    temp_res = temp_res - paths.top() - 1;
                    paths.pop();
                }
                paths.push(temp_len);
                temp_res += temp_len + 1;
                if (is_file)
                {
                    res = res < temp_res ? temp_res : res;
                    is_file = false;
                }
                temp_len = 0;
                level = 0;
                break;
            case '\t':
                level++;
                break;
            default:
                // 说明不是/n和/t
                temp_len++;
                if (input[i] == '.')
                {
                    is_file = true;
                }
                break;
            }
        }

        // 判断最后一个文件或目录
        while (paths.size() > level)
        {
            temp_res = temp_res - paths.top() - 1;
            paths.pop();
        }
        paths.push(temp_len);
        temp_res += temp_len + 1;
        if (is_file)
        {
            res = res < temp_res ? temp_res : res;
            is_file = false;
        }
        temp_len = 0;
        level = 0;
        return res == 0 ? 0 : res - 1;
    }
};

int main(int argc, char const *argv[])
{
    string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    Solution solution = Solution();
    cout << solution.lengthLongestPath(input);

    return 0;
}
