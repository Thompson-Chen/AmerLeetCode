#include <iostream>
#include <vector>
using namespace std;
// 平均耗时4ms，空间复杂度700KB左右

// 密码合规检测，如果合规则返回true，反之返回false
bool pwd_check(string pwd)
{
    // 密码长度校验，不小于6不大于12
    int len = pwd.length();
    if(len < 6 or len > 12)
    {
        return false;
    }

    // 字符校验
    bool lower_case = false;
    bool upper_case = false;
    bool is_digit = false;
    bool special_char = false;

    // 1. 字符构成校验
    for(int i = 0; i < len; i++)
    {
        if(pwd[i]>='a' and pwd[i] <= 'z')
        {
            lower_case = true;
        }
        else if (pwd[i]>='A' and pwd[i] <= 'Z')
        {
            upper_case = true;
        }
        else if (pwd[i]>='0' and pwd[i] <= '9')
        {
            is_digit = true;
        }
        else if(pwd[i] == '!' || pwd[i] == '@' || pwd[i] == '#' || pwd[i] == '$')
        {
            special_char = true;
        }
        else
        {
            return false;
        }
    }

    // 2. 字符类型数量校验
    if(!special_char)
    {
        return false;
    }
    // 思考下“三个bool值至少有两个为true，则判为true”怎么判断【另一种方式：(a==b)?a:c】
    if(!(upper_case?(lower_case||is_digit):(lower_case&&is_digit)))
    {
        return false;
    }
    return true;
}

int main()
{   
    string s = "";
    cin>>s;
    // 难点：字符串读取
    // substr + vector动态数组（substr用不了就用字符串拼接‘+’，vector用不了就开一个恒定长度为100的静态数组（因为输入字符串长度不大于100））
    int start = 0;
    int end = start;
    vector<string> pwd;
    while(end < s.length())
    {
        if(s[end]== ',')
        {
            pwd.push_back(s.substr(start,end-start));
            start = end+1;
        }
        end++;
    }
    // 思考下为什么要加这一行
    pwd.push_back(s.substr(start,end-start));

    // 逐行检测
    for(auto &item: pwd)
    {
        if(pwd_check(item))
        {
            cout<<item<<endl;
        }
    }


    return 0;
}