// 特定顺序遍历二维数组
// 螺旋矩阵
// https://leetcode.cn/problems/spiral-matrix/
# include<iostream>
# include <vector>
using namespace std;
// 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
// 输出：[1,2,3,6,9,8,7,4,5]
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // 设置上下左右边界（由题目已知matrix不为空，至少有一个元素）
        int u = 0;
        int d = matrix.size() -1;
        int l = 0;
        int r = matrix[0].size() -1;
        vector<int> ans;
        while(true)
        {
            for (int i = l; i <= r; i++)ans.push_back(matrix[u][i]);
            if(++u > d) break;
            for(int i = u; i <= d; i++)ans.push_back(matrix[i][r]);
            if(--r < l) break;
            for(int i = r; i >= l; i--)ans.push_back(matrix[d][i]);
            if(--d < u) break;
            for(int i = d; i >= u; i--)ans.push_back(matrix[i][l]);
            if(++l > r) break;
        }
        return ans;
    }
};

int main()
{

}

// 参考：设置上下边界
/**
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        if(matrix.empty()) return ans; //若数组为空，直接返回答案
        int u = 0; //赋值上下左右边界
        int d = matrix.size() - 1;
        int l = 0;
        int r = matrix[0].size() - 1;
        while(true)
        {
            for(int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); //向右移动直到最右
            if(++ u > d) break; //重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            for(int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); //向下
            if(-- r < l) break; //重新设定有边界
            for(int i = r; i >= l; --i) ans.push_back(matrix[d][i]); //向左
            if(-- d < u) break; //重新设定下边界
            for(int i = d; i >= u; --i) ans.push_back(matrix[i][l]); //向上
            if(++ l > r) break; //重新设定左边界
        }
        return ans;
    }
};
*/