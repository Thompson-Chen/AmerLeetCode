// 交替位二进制数
// 进制转换
// https://leetcode.cn/problems/binary-number-with-alternating-bits/description/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        // 100%/5.9%
        // 因为log(2,n) = log(c,n)/log(c,2)（其中c为任意数）
        int m = log(n) / log(2); // 返回的是double，使用int进行取整
        bool is_continues = false; // 判断是否连续，即前一个是否是1
        for(;m>=0;--m)
        {
            int temp = pow(2,m);
            if(n-temp>=0)
            {
                if(is_continues)
                {
                    return false;
                }
                else
                {
                    is_continues = true;
                    n -= temp;
                }
            }
            else
            {
                if(!is_continues)
                {
                    return false;
                }
                else
                {
                    is_continues = false;
                }
                
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    int n = 1;
    Solution solution = Solution();
    solution.hasAlternatingBits(n);
    return 0;
}
