// 数字的补数
// 进制转换
// https://leetcode.cn/problems/number-complement/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
class Solution
{
public:
    int findComplement(int num)
    {
        // 100/19.81
        int highbit = 0;
        // 找到最高位的1，因为最高位1前面的0是不用转成1的
        for (int i = 1; i <= 30; ++i)
        {
            if (num >= (1 << i))
            {
                highbit = i;
            }
            else
            {
                break;
            }
        }

        int mask = highbit == 30 ? 0x7fffffff : (1 << (highbit+1)) - 1;
        return num ^ mask;
    }
};

int main(int argc, char const *argv[])
{
    int a = 5;
    Solution solution = Solution();
    cout << solution.findComplement(a);
    return 0;
}
