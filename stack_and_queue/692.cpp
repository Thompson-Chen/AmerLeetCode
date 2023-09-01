// 求前 K 个高频元素
// 前K个高频单词
// https://leetcode.cn/problems/top-k-frequent-words/
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cctype>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        // /** 方法1：直接调用sort函数进行排序然后再比较 */
        // /** 方法2：先遍历一次获取重复次数（hash），然后再利用最大堆获取前k个高频元素(没跑通全部，样例通过率大概28%) */
        // unordered_map<string, int> umap;
        // for (int i = 0; i < words.size(); i++)
        // {
        //     if (umap.count(words[i]))
        //     {
        //         umap[words[i]]++;
        //     }
        //     else
        //     {
        //         umap[words[i]] = 1;
        //     }
        // }

        // // 然后利用最小堆这一数据结构，返回前K个元素
        // priority_queue<pair<int, string>> q;
        // for (const auto &kvp : umap)
        // {
        //     q.emplace(kvp.second, kvp.first);
        // }
        // vector<string> res;
        // stack<string> stk;
        // int t_k = INT_MAX;
        // while (q.top().first == t_k or res.size() + stk.size() < k)
        // {
        //     if (q.top().first < t_k)
        //     {
        //         // 把级别更高的元素全部存到数组中
        //         while (!stk.empty())
        //         {
        //             res.push_back(stk.top());
        //             stk.pop();
        //         }
        //         // 把当前级别的元素存到stk中
        //         stk.emplace(q.top().second);
        //         t_k = q.top().first;
        //     }
        //     else if (q.top().first == t_k)
        //     {
        //         vector<string> tmp_strs;
        //         while (!stk.empty() and stk.top()[0] < q.top().second[0])
        //         {
        //             tmp_strs.push_back(stk.top());
        //             stk.pop();
        //         }
        //         stk.emplace(q.top().second);
        //         for (int j = tmp_strs.size() - 1; j >= 0; j--)
        //         {
        //             stk.emplace(tmp_strs[j]);
        //         }
        //     }
        //     q.pop();
        // }

        // while (!stk.empty())
        // {
        //     res.push_back(stk.top());
        //     stk.pop();
        // }

        // return res;

        /** 官方题解 */
        // 哈希表 + 排序
        unordered_map<string, int> cnt;
        for (auto &word : words)
        {
            ++cnt[word];
        }

        vector<string> rec;
        for (auto &item : cnt)
        {
            rec.emplace_back(item.first);
        }
        sort(rec.begin(), rec.end(), [&](const string &a, const string &b) -> bool
             { return cnt[a] == cnt[b] ? a < b : cnt[a] > cnt[b]; });
        rec.erase(rec.begin() + k, rec.end());
        return rec;
        // 优先队列
        unordered_map<string, int> cnt;
        for (auto& word : words) {
            cnt[word]++;
        }
        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> que(cmp);
        for (auto& it : cnt) {
            que.emplace(it);
            if (que.size() > k) {
                que.pop();
            }
        }
        vector<string> ret(k);
        for (int i = k - 1; i >= 0; i--) {
            ret[i] = que.top().first;
            que.pop();
        }
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution = Solution();
    vector<string> test = {"i", "love", "leetcode", "i", "love", "coding"};
    solution.topKFrequent(test, 2);
    return 0;
}
