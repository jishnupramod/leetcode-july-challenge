/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        if (num.size() < 3)
            return {};
        set<vector<int>> ans;
        unordered_map<int, int> mp;
        int x, y;
        for (int i : num) mp[i]++;
        vector<int> nums;
        for (auto it=mp.begin(); it!=mp.end(); ++it) {
            for (int i=0; i<min(3, it->second); ++i)
                nums.push_back(it->first);
        }
        int n = nums.size();
        for (int i=0; i<n-1; ++i) {
            x = nums[i];
            --mp[x];
            for (int j=i+1; j<n; ++j) {
                y = nums[j];
                --mp[y];
                if (mp[-(x+y)]) {
                    vector<int> triplet = {x, y, -(x+y)};
                    sort(triplet.begin(), triplet.end());
                    ans.emplace(triplet);
                }
                ++mp[y];
            }
            ++mp[x];
            
        }
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};