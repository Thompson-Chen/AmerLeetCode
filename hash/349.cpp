// 哈希表的查找、插入及删除
// 两个数组的交集
// https://leetcode.cn/problems/intersection-of-two-arrays/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// 方法：排序 + 双指针
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int p1 = 0, p2 = 0;

        vector<int> intersections;
        while (p1 < nums1.size() && p2 < nums2.size())
        {
            if (nums1[p1] == nums2[p2] and (!intersections.size() || nums1[p1] != intersections.back()))
            {
                intersections.push_back(nums1[p1]);
                p1++;
                p2++;
            }
            else if (nums1[p1] < nums2[p2])
            {
                p1++;
            }
            else
            {
                p2++;
            }
        }
        return intersections;
    }
};

// 方法：哈希集合
// class Solution
// {
// public:
//     vector<int> getIntersection(unordered_set<int> &set1, unordered_set<int> &set2)
//     {
//         if (set1.size() > set2.size())
//         {
//             return getIntersection(set2, set1);
//         }
//         vector<int> intersection;
//         for (auto &num : set1)
//         {
//             if (set2.count(num)) // 通常用于检查容器中是否存在元素。如果元素存在于容器中，则该函数返回1，否则返回0
//             {
//                 intersection.push_back(num);
//             }
//         }
//         return intersection;
//     }

//     vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
//     {
//         // 两个集合（哈希集合）
//         unordered_set<int> set1, set2;
//         for (auto& num : nums1) {
//             set1.insert(num);
//         }
//         for (auto& num : nums2) {
//             set2.insert(num);
//         }
//         return getIntersection(set1, set2);
//     }
// };

int main()
{
    Solution *s = new Solution();
    vector<int> n1 = {4,9,5};
    vector<int> n2 = {9,4,9,8,4};
    vector<int> res = s->intersection(n1,n2);
    for (int i = 0; i < res.size(); i++)
    {
        cout<< res[i]<<" ";
    }
    

}