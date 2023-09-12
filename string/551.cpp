// 字符的统计
// 学生出勤记录 I
// https://leetcode.cn/problems/student-attendance-record-i/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        // 40.43/36.6
        // 条件1：学生缺勤（'A'）严格 少于两天。
        int cnt_A = 0;
        for(char c: s)
        {
            if(c == 'A')
            {
                cnt_A++;
            }
        }

        if(cnt_A>=2){
            return false;
        }
        // 条件2：学生 不会 存在 连续 3 天或 连续 3 天以上的迟到（'L'）记录。
        int found = s.find("LLL");
        if(found != string::npos) {
            return false;
        }
        else
        {
            return true;
        }
    }
};