/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/


class Solution {
public:
    string addBinary(string a, string b) {
        int alen = a.length(), blen = b.length();
        vector<char> ans(max(alen, blen) + 1);
        int i = alen-1, j = blen-1, k = ans.size()-1;
        int carry = 0;
        while (i >= 0 and j >= 0) {
            int sum = a[i--]-'0' + b[j--]-'0' + carry;
            ans[k--] = (sum % 2) + '0';
            carry = sum / 2;
        }
        while (i >= 0) {
            int sum = a[i--]-'0' + carry;
            ans[k--] = (sum % 2) + '0';
            carry = sum / 2;
        }
        while (j >= 0) {
            int sum = b[j--]-'0' + carry;
            ans[k--] = (sum % 2) + '0';
            carry = sum / 2;
        }
        string res = "";
        if (carry) {
            ans[k] = '1';
            res += "1";
        }
        for (int i=1; i<ans.size(); ++i)
            res += ans[i];
        return res;
    }
};