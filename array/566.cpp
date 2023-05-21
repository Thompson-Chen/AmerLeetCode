// 二维数组变换
// 重塑矩阵
// https://leetcode.cn/problems/reshape-the-matrix/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        // 86.96/34.89
        int m = mat.size();
        int n = mat[0].size();
        if(m*n != r*c)
        {
            return mat;
        }

        vector<vector<int>> res(r,vector<int>(c,0));
        int count = 0;
        for(auto & row: mat)
        {
            for(auto & num: row)
            {
                res[(count)/(c)][(count)%(c)] = num;
                count++;
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}