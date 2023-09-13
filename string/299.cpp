// 数字与字符串间转换
// 猜数字游戏
// https://leetcode.cn/problems/bulls-and-cows/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        // 80.03/79.1
        int bulls = 0, cows = 0;
        int secret_cnt[10] = {0};
        int guess_cnt[10] = {0};
        // 先统计公牛树
        for (int i = 0; i < secret.length(); i++)
        {
            if (secret[i] == guess[i])
            {
                bulls++;
            }
            secret_cnt[secret[i] - '0']++;
            guess_cnt[guess[i] - '0']++;
        }

        for (int i = 0; i < 10; i++)
        {
            cows += min(secret_cnt[i], guess_cnt[i]);
        }

        cows -= bulls;

        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};