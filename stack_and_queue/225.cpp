#include <iostream>
#include <queue>
using namespace std;

class MyStack
{
private:
    queue<int> q1; // 真实栈顺序
    queue<int> q2; // 辅助队列，用于push
public:
    MyStack()
    {
    }

    void push(int x)
    {
        q2.push(x);
        while(!q1.empty())
        {
            int temp = q1.front();
            q2.push(temp);
            q1.pop();
        }
        queue<int> temp_q = q1;
        q1 = q2;
        q2 = temp_q;
    }

    int pop()
    {
        int num = q1.front();
        q1.pop();
        return num;
    }

    int top()
    {
        return q1.front();
    }

    bool empty()
    {
        if(q1.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */