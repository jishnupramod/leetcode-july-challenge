/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
*/


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int sum = digits.back() + 1;
        int carry = sum / 10;
        while (carry) {
            ans.push_back(0);
            digits.pop_back();
            if (! digits.empty()) {
                sum = digits.back() + 1;
                carry = sum / 10;
            } else
                break;
        }
        if (! carry)
            ans.push_back(sum);
        else
            ans.push_back(carry);
        if (! digits.empty())
            digits.pop_back();
        while (!digits.empty()) {
            ans.push_back(digits.back());
            digits.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};