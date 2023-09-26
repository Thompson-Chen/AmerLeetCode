

// 数字与字符串间转换
// 比较版本号
// https://leetcode.cn/problems/compare-version-numbers/description/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        // 100%/7.12%
        stringstream v1(version1);
        stringstream v2(version2);
        string temp;
        vector<int> v1_arr;
        int num = 0, cnt = 0;
        while (getline(v1, temp, '.'))
        {
            num = stoi(temp);

            v1_arr.push_back(num);
        }

        while (getline(v2, temp, '.'))
        {
            num = stoi(temp);
            if (cnt < v1_arr.size())
            {
                if (v1_arr[cnt] > num)
                {
                    return 1;
                }
                else if (v1_arr[cnt] < num)
                {
                    return -1;
                }
            }
            else if (num > 0)
            {
                return -1;
            }
            cnt++;
        }
        while(cnt < v1_arr.size())
        {
            if(v1_arr[cnt++]>0)
            {
                return 1;
            }
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution = Solution();
    string v1 = "0.1";
    string v2 = "1.1";
    cout << solution.compareVersion(v1, v2);
    return 0;
}
