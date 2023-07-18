// 单调栈
// 股票价格跨度
// https://leetcode.cn/problems/online-stock-span/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class StockSpanner
{
public:
    vector<int> stocks;
    stack<int> stk;
    StockSpanner()
    {
    }

    int next(int price)
    {
        // 单调栈 98.21%/22.43%
        stocks.push_back(price);
        while (!stk.empty() and price >= stocks[stk.top()])
        {
            stk.pop();
        }
        int idx = stocks.size() - 1;
        int span = 1;
        if (!stk.empty())
        {
            span = idx - stk.top();
        }
        else
        {
            span = idx + 1;
        }

        stk.push(idx);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */