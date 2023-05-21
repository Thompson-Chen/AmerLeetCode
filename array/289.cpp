// 二维数组变换
// 生命游戏
// https://leetcode.cn/problems/game-of-life/description/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool hasLive(vector<vector<int>> &board, int i, int j)
    {
        int m = board.size();
        int n = board[0].size();

        if (i >= 0 and i < m and j >= 0 and j < n)
        {
            if (board[i][j] == 1 or board[i][j] == 2)
                return true;
        }

        return false;
    }
    void gameOfLife(vector<vector<int>> &board)
    {
        // 原定更新：使用复合状态
        // 由题意：
        // 周围活细胞数<2，则活细胞-》死细胞；状态：2（先活后死）
        // 周围活细胞数为2或3，则活细胞-》活细胞；状态：1（一直活）
        // 周围活细胞数刚好为3，则死细胞-》活细胞；状态：3（先死后活）
        // 周围活细胞数>3，则活细胞-》死细胞；状态：2（先活后死）
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int count = 0; // 统计活细胞的个数
                if (this->hasLive(board, i - 1, j - 1))
                    count++;
                if (this->hasLive(board, i - 1, j))
                    count++;
                if (this->hasLive(board, i - 1, j + 1))
                    count++;
                if (this->hasLive(board, i, j - 1))
                    count++;
                if (this->hasLive(board, i, j + 1))
                    count++;
                if (this->hasLive(board, i + 1, j - 1))
                    count++;
                if (this->hasLive(board, i + 1, j))
                    count++;
                if (this->hasLive(board, i + 1, j + 1))
                    count++;

                if (count == 3 and board[i][j] == 0)
                {
                    board[i][j] = 3;
                }
                else if (board[i][j]==1 and (count < 2 or count > 3))
                {
                    board[i][j] = 2;
                }
            }
        }

        // 修改
        for (auto &row : board)
        {
            for (auto &ele : row)
            {
                if (ele == 2)
                {
                    ele = 0;
                }
                else if (ele == 3)
                {
                    ele = 1;
                }
            }
        }
    }
};

int main()
{
    vector<vector<int>> board = {{0,0}};
    // vector<vector<int>> board = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}, {0, 0, 0}};
    Solution *s = new Solution();
    s->gameOfLife(board);

    return 0;
}