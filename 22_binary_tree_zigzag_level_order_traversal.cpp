/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/


// 1st approach
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        deque<TreeNode*> q;
        vector<vector<int>> lvls;
        q.push_back(root);
        int genPop = 0;
        bool rev = false;
        while (!q.empty()) {
            if (genPop == 0) {
                genPop = q.size();
                vector<TreeNode*> lvl_nodes(q.begin(), q.end());
                vector<int> lvl;
                if (rev) {
                    for (int i=lvl_nodes.size()-1; i>=0; --i)
                        lvl.push_back(lvl_nodes[i]->val);
                    rev = false;
                } else {
                    for (int i=0; i<lvl_nodes.size(); ++i)
                        lvl.push_back(lvl_nodes[i]->val);
                    rev = true;
                }
                lvls.push_back(move(lvl));
            }
            TreeNode* node = q.front();
            q.pop_front();
            --genPop;
            if (node->left)
                q.push_back(node->left);
            if (node->right)
                q.push_back(node->right);
        }
        return lvls;
    }
};



// More concise and efficient solution
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        bool rev = false;
        int index;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> lvl(size);
            for (int i=0; i<size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                index = rev ? size-1-i : i;
                lvl[index] = node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            rev = !rev;
            ans.push_back(move(lvl));
        }
        return ans;
    }
};