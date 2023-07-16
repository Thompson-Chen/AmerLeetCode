// 栈的实现
// 面试题 03.01. 三合一
// https://leetcode.cn/problems/three-in-one-lcci/
#include <iostream>
#include <vector>
using namespace std;


class TripleInOne
{
public:
    vector<int> vec; // 存储栈中的所有元素
    vector<int> ptrs; // ptrs[i] 存储第 i 个栈中下一个需要填充的位置的索引，注意不是指向栈顶，而是栈顶的上面
    int stackSize;
    TripleInOne(int stackSize)
    {
        this->stackSize = stackSize;
        vec.resize(3*stackSize);

        ptrs.resize(3);
        ptrs[0] = 0;
        ptrs[1] = stackSize;
        ptrs[2] = stackSize * 2;
    }

    void push(int stackNum, int value)
    {
        // 栈满时不压入元素
        if(ptrs[stackNum] < (stackNum + 1)*stackSize)
        {
            vec[ptrs[stackNum]] = value;
            ptrs[stackNum]++;
        }
    }

    int pop(int stackNum)
    {
        // 栈空时返回-1
        if(isEmpty(stackNum))return -1;
        return vec[--ptrs[stackNum]];
    }

    int peek(int stackNum)
    {
        // 栈空时返回-1
        if(isEmpty(stackNum))return -1;
        return vec[ptrs[stackNum]-1];
    }

    bool isEmpty(int stackNum)
    {
        return  ptrs[stackNum] == stackSize * stackNum;
    }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * TripleInOne* obj = new TripleInOne(stackSize);
 * obj->push(stackNum,value);
 * int param_2 = obj->pop(stackNum);
 * int param_3 = obj->peek(stackNum);
 * bool param_4 = obj->isEmpty(stackNum);
 */