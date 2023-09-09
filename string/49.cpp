// 字符的统计
// 字母异位词分组
// https://leetcode.cn/problems/group-anagrams/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 5.13/6.59
        unordered_map<string,vector<string>> hash;
        for(string s: strs)
        {
            int arr[26] = {0};
            for(char c: s)
            {
                arr[c-'a']++;
            }
            string prefix = arr2str(arr);
            hash[prefix].push_back(s);
        }

        vector<vector<string>> res;
        for(auto& pair:hash)
        {
            res.push_back(pair.second);
        }
        return res;
    }

    string arr2str(int arr[26])
    {
        string s = "";
        for (int i = 0; i < 26; i++)
        {
            s += to_string(arr[i])+"_";
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> arr = {"bdddddddddd","bbbbbbbbbbc"};
    Solution solution = Solution();
    solution.groupAnagrams(arr);
    return 0;
}
