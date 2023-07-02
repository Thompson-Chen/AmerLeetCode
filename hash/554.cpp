// 哈希表与统计
// 砖墙
// https://leetcode.cn/problems/brick-wall/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        // 方法1：不使用hash，使用类似前缀和的思想，只有当当前要划线的位置刚好等于某一行的某个元素时，计数器才不加1
        // 这种直接模拟法是无法通过全部测试用例的（71/87），主要是会超时，如[[100000000,100000000],[100000000,100000000]]
        // bool only_one = true;
        // for (auto &line : wall)
        // {
        //     for (int i = 1; i < line.size(); i++)
        //     {
        //         line[i] += line[i - 1];
        //         only_one = false;
        //     }
        // }

        // int min = wall.size();
        // if (!only_one)
        // {
        //     for (int i = 1; i < wall[0].back(); i++)
        //     {
        //         int temp = wall.size();
        //         for (auto &line : wall)
        //         {
        //             if (find(line.begin(), line.end(), i) != line.end())
        //             {
        //                 temp -= 1;
        //             }
        //         }
        //         min = temp < min ? temp : min;
        //     }
        // }

        // return min;

        // 方法2：在方法1的代码基础上引入hashmap (86.9%/96.12%)
        unordered_map<int, int> umap;
        for (auto &line : wall)
        {
            for (int i = 0; i < line.size()-1; i++)
            {
                line[i+1] += line[i];
                if (umap.count(line[i]))
                {
                    umap[line[i]] += 1;
                }
                else
                {
                    umap[line[i]] = 1;
                }
            }
        }

        int min = wall.size();

        for (auto iter = umap.begin(); iter != umap.end(); ++iter)
        {
            int temp = wall.size() - iter->second;
            min = temp < min ? temp : min;
        }
        return min;
    }
};

int main()
{
    // vector<vector<int>> wall = {{6}, {6}, {2, 4}, {6}, {1, 2, 2, 1}, {6}, {2, 1, 2, 1}, {1, 5}, {4, 1, 1}, {1, 4, 1}, {4, 2}, {3, 3}, {2, 2, 2}, {5, 1}, {5, 1}, {6}, {4, 2}, {1, 5}, {2, 3, 1}, {4, 2}, {1, 1, 4}, {1, 3, 1, 1}, {2, 3, 1}, {3, 3}, {3, 1, 1, 1}, {3, 2, 1}, {6}, {3, 2, 1}, {1, 5}, {1, 4, 1}};
    // vector<vector<int>> wall = {{1},{1},{1}};
    vector<vector<int>> wall = {{1,2,2,1},{3,1,2},{1,3,2},{2,4},{3,1,2},{1,3,1,1}};
    Solution s = Solution();
    s.leastBricks(wall);
    return 0;
}