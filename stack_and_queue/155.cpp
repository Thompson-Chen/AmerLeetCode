// 最小/大栈
// 最小栈
// https://leetcode.cn/problems/min-stack/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class MinStack
{
    stack<int> min_stk;
    stack<int> stk;

public:
    /** initialize your data structure here. */

    MinStack()
    {
        min_stk.emplace(INT_MAX);
    }

    void push(int x)
    {
        stk.emplace(x);
        if (x < min_stk.top())
        {
            min_stk.emplace(x);
        }
        else
        {
            min_stk.emplace(min_stk.top());
        }
    }

    void pop()
    {
        stk.pop();
        min_stk.pop();
    }

    int top()
    {
        return stk.top();
    }

    int getMin()
    {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */