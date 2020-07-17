/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
*/


// O(nlogn) Version
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i : nums) ++mp[i];
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return mp[a] > mp[b];
        });
        set<int> ans;
        int cnt = 0;
        for (int i : nums) {
            if (ans.find(i) == ans.end()) {
                ans.insert(i);
                ++cnt;
            }
            if (cnt == k) break;
        }
        vector<int> res(ans.begin(), ans.end());
        return res;
    }
};


// Solution using heap
class Solution {
private:
    unordered_map<int, int> mp;
    int extract_max(vector<int>& nums) {
        int max = nums[0];
        nums[0] = nums.back();
        nums.pop_back();
        max_heapify(nums, 0);
        return max;
    }
    void max_heapify(vector<int>& nums, int i) {
        int l = 2*i;
        int r = 2*i+1;
        int most_common;
        if (l < nums.size() and mp[nums[l]] > mp[nums[i]])
            most_common = l;
        else
            most_common = i;
        if (r < nums.size() and mp[nums[r]] > mp[nums[most_common]])
            most_common = r;
        if (i != most_common) {
            swap(nums[i], nums[most_common]);
            max_heapify(nums, most_common);
        }
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        for (int i : nums) ++mp[i];
        set<int> s;
        for (int i : nums) s.insert(i);
        vector<int> A(s.begin(), s.end()), ans(k);
        int n = A.size();
        for (int i=n/2; i>=0; --i)
            max_heapify(A, i);
        for (int i=0; i<k; ++i) 
            ans[i] = extract_max(A);
        return ans;
    }
};