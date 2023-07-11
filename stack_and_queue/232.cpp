#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
private:
    stack<int> in_stk;
    stack<int> out_stk;

public:
    MyQueue()
    {
    }

    void push(int x)
    {
        this->in_stk.push(x);
    }

    int pop()
    {
        if (this->out_stk.empty())
        {
            while (!this->in_stk.empty())
            {
                int temp = this->in_stk.top();
                this->in_stk.pop();
                this->out_stk.push(temp);
            }
        }
        int num = this->out_stk.top();
        this->out_stk.pop();
        return num;
    }

    int peek()
    {
        if (this->out_stk.empty())
        {
            while (!this->in_stk.empty())
            {
                int temp = this->in_stk.top();
                this->in_stk.pop();
                this->out_stk.push(temp);
            }
        }
        int num = this->out_stk.top();
        return num;
    }

    bool empty()
    {
        if(this->out_stk.empty() and this->in_stk.empty())
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
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
**/