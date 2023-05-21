// 二维数组及滚动数组
// 甲板上的战舰
// https://leetcode.cn/problems/battleships-in-a-board/
#include <iostream>
#include <vector>
// set容器教程：https://blog.csdn.net/weixin_51566349/article/details/128128227
#include <set>
using namespace std;

class Solution
{
public:
    int countBattleships(vector<vector<char>> &board)
    {
        // 进阶要求：
        // 进阶：你可以实现一次扫描算法，并只使用 O(1) 额外空间，并且不修改 board 的值来解决这个问题吗？

        // 思路：开一个set容器，逐行扫描，把该行的舰数统计出来，并把可能在下行续上的战舰下标加入，把在当前行断掉的战舰下标删除
        int count = 0;         // 战舰计数器
        set<int> s;            // 存储上一行可能续接的战舰位置下标（用于竖着的战舰）
        bool is_cutoff = true; // 同行判断x是否前面挨着x （用于横着的战舰）
        bool is_multi = false;

        for (auto &line : board)
        {
            is_cutoff = true;
            is_multi = false;
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] == 'X')
                {
                    if (s.find(i) == s.end())
                    {
                        // 不存在这个元素 - 说明至少从这行以及这行以前的甲板来看，不存在竖着的战舰
                        if (is_cutoff)
                        {
                            count++;
                            is_cutoff = false;
                        }
                        else
                        {
                            is_multi = true;
                        }
                        if (i == line.size() - 1 and is_cutoff==false and is_multi == false)
                        {
                            s.insert(i);
                        }
                    }
                }
                else if (line[i] == '.')
                {
                    if (s.find(i) != s.end())
                    {
                        // 上一行的同一位置为“X”
                        s.erase(i);
                    }
                    if (is_multi == false and is_cutoff == false)
                    {
                        s.insert(i - 1);
                    }
                    is_cutoff = true;
                    is_multi = false;
                }
            }
        }

        return count;
    }
};

int main()
{
    vector<vector<char>> board = {{'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}};
    Solution *s = new Solution();
    cout << s->countBattleships(board);
    return 0;
}