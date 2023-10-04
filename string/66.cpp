// 加一
// 高精度运算
// https://leetcode.cn/problems/plus-one/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        // 44.65/8.86
        int i = digits.size()-1;
        do
        {
            digits[i] = (digits[i] + 1) % 10;
        } while (digits[i] == 0 and --i >= 0 );

        if(digits[0] == 0)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> vec = {9,9,9};
    Solution solution = Solution();
    solution.plusOne(vec);
    return 0;
}
