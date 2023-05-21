// 特定顺序遍历二维数组
// 螺旋矩阵II
// https://leetcode.cn/problems/spiral-matrix-ii/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        // 二维数组初始化
        vector<vector<int>> res(n, vector<int>(n, 0));

        // 同54一样，也是设置上下左右边界，遍历赋值
        int u = 0;
        int d = n - 1;
        int l = 0;
        int r = n - 1;
        int count = 0;
        while (true)
        {
            for (int i = l; i <= r; i++)
                res[u][i] = ++count;
            if (++u > d)
                break;
            for (int i = u; i <= d; i++)
                res[i][r] = ++count;
            if (--r < l)
                break;
            for (int i = r; i >= l; i--)
                res[d][i] = ++count;
            if (--d < u)
                break;
            for (int i = d; i >= u; i--)
                res[i][l] = ++count;
            if (++l > r)
                break;
        }
        return res;
    }
};

int main()
{
    return 0;
}