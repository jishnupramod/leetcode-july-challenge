/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
(ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        stack<vector<int>> st;
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        vector<int> temp;
        int genPop = 1;
        q.push(root);
        int flag = 0;
        while (!q.empty()) {
            if (flag and genPop == 0) {
                st.push(temp);
                temp.clear();
                genPop = q.size();
            }
            flag = 1;
            TreeNode* node = q.front();
            q.pop();
            temp.push_back(node->val);
            --genPop;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            
        }
        st.push(temp);
        while (!st.empty()) {
            vector<int> level = st.top();
            res.push_back(level);
            st.pop();
        }
        return res;
    }
};
