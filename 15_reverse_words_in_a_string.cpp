/*
Given an input string, reverse the string word by word.

 

Example 1:

Input: "the sky is blue"
Output: "blue is sky the"
Example 2:

Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
Example 3:

Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Note:

A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.
 

Follow up:

For C programmers, try to solve it in-place in O(1) extra space.
*/


// Without using additional data structures other than output string
class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        s = " " + s;
        int len = s.length(), j = -1;
        for (int i=len-1; i>=0; --i) {
            if (s[i] != ' ' and j == -1)
                j = i;
            else if (s[i] == ' ' and j != -1) {
                for (int k=i+1; k<=j; ++k)
                    ans += s[k];
                ans += " ";
                j = -1;
            }
        }
        len = ans.length();
        ans = ans.substr(0, len-1);
        return ans;
    }
};


// By using Stack
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        stack<string> st;
        string temp;
        while (ss >> temp) 
            st.push(temp);
        if (st.empty())
            return "";
        string ans = "";
        while (st.size() > 1) {
            ans += st.top();
            st.pop();
            ans += " ";
        }
        ans += st.top();
        return ans;
    }
};