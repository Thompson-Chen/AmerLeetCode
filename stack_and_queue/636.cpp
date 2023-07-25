// 栈与括号匹配
// 函数的独占时间
// https://leetcode.cn/problems/exclusive-time-of-functions/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

class Solution
{
public:
    struct log
    {
        int id;
        string status;
        int timestamp;
    };
    log getlog(string s)
    {
        log mylog;
        stringstream ss(s);
        string id, status, timestamp;

        getline(ss, id, ':');
        getline(ss, status, ':');
        getline(ss, timestamp, ':');

        mylog.id = stoi(id);
        mylog.status = status;
        mylog.timestamp = stoi(timestamp);
        return mylog;
    }
    vector<int> exclusiveTime(int n, vector<string> &logs)
    {
        // 初始化
        vector<int> result(n, 0);
        stack<log> stk;
        int last_end = -1; // 用于记录上一次end的时间戳
        for (auto &s : logs)
        {
            log item = getlog(s);
            if (item.status == "start")
            {
                if (!stk.empty())
                {
                    result[stk.top().id] += item.timestamp - stk.top().timestamp;
                }
                stk.push(item);
            }
            else
            {
                if (!stk.empty())
                {
                    log temp = stk.top();
                    if (temp.id == item.id)
                    {
                        result[item.id] += item.timestamp - temp.timestamp + 1;
                        stk.pop();
                        // 把倒数第二个元素的timestemp刷新
                        if (!stk.empty())
                        {
                            temp = stk.top();
                            stk.pop();
                            temp.timestamp = item.timestamp + 1;
                            stk.push(temp);
                        }
                    }
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution = Solution();
    Solution::log mylog = solution.getlog("0:start:5");
    cout << mylog.id << endl;

    return 0;
}