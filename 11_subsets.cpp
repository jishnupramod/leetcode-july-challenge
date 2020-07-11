/*
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/


// Backtracking Solution (Recursive)
class Solution {
private:
    void search(vector<int> nums, vector<int> ss, vector<vector<int>>& ps, int i, int n) {
        if (i == n) {
            ps.push_back(ss);
        }
        else {
            ss.push_back(nums[i]);
            search(nums, ss, ps, i+1, n);
            ss.pop_back();
            search(nums, ss, ps, i+1, n);
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> powerset;
        vector<int> subset;
        int n = nums.size();
        search(nums, subset, powerset, 0, n);
        return powerset;
    }
};

// Lexicographic generation based on the mapping between binary bitmasks and the corresponding permutations / combinations / subsets.
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for (int i=0; i < (1<<n); ++i) {
            vector<int> sub;
            for (int j=0; j<n; ++j) {
                if (i & 1 << j)
                    sub.push_back(nums[j]);
            }
            res.push_back(move(sub));
        }
        return res;
    }
};