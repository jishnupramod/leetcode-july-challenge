/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/


class Solution {
private:
    bool dfs(vector<vector<char>>& board, int i, int j, string word) {
        if (!word.length())
            return true;
        if (i<0 or j<0 or i>=board.size() or j>=board[0].size() or board[i][j] != word[0]) {           
            
            return false;
        }
        char ch = board[i][j];
        board[i][j] = '#';
        string sub = word.substr(1);
        bool res = dfs(board, i+1, j, sub) or dfs(board, i-1, j, sub) or dfs(board, i, j+1, sub) or dfs(board, i, j-1, sub);
        board[i][j] = ch;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int r = board.size();
        int c = board[0].size();
        int index;
        vector<vector<char>> dupl(board.begin(), board.end());
        for (int i=0; i<r; ++i) {
            for (int j=0; j<c; ++j) {
                if (dupl[i][j] == word[0]) {
                    index = 0;
                    if (dfs(board, i, j, word))
                        return true;
                }
            }
        }
        return false;
    }
};