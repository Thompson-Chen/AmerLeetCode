// 特定顺序遍历二维数组
// 对角线遍历
// https://leetcode.cn/problems/diagonal-traverse/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        // 74.6/30.8
        vector<int> res;
        int m = mat.size();
        int n = mat[0].size();

        // (官方)直接模拟法
        // 一共有 m+n-1 条对角线
        // 当为奇数时，从左下往右上遍历（行-1，列+1），直至到达边缘
        // 当为偶数时，从右上往左下遍历（行+1，列-1），直至到达边缘
        // 起点不同：
        // 对奇数边，当i<=m时，起点为(i-1,0)；当i>m时，起点为(m-1, i-m)
        // 对偶数边，当i<=n时，起点为(0,i-1)；当i>n时，起点为(i-n, n-1)
        int row = 0, col = 0;
        for (int i = 1; i <= m + n - 1; i++)
        {
            if (i % 2 == 1)
            {
                // 奇数
                row = i <= m ? i - 1 : m - 1;
                col = i <= m ? 0 : i - m;
                while (row >= 0 and row < m and col >= 0 and col < n)
                {
                    res.push_back(mat[row--][col++]);
                }
            }
            else
            {
                // 偶数
                row = i <= n ? 0 : i - n;
                col = i <= n ? i - 1 : n - 1;
                while (row >= 0 and row < m and col >= 0 and col < n)
                {
                    res.push_back(mat[row++][col--]);
                }
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}