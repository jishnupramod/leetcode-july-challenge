/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

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
private:
    unordered_map<int, int> node_index;
    int poi;
    vector<int> io, po;
    TreeNode* build(int l, int r) {
        if (l == r) {
            --poi;
            return new TreeNode(io[l]);
        }
        if (l > r)
            return NULL;
        int node_val = po[poi];
        --poi;
        int root_index = node_index[node_val];
        TreeNode* root = new TreeNode(node_val);
        root->right = build(root_index+1, r);
        root->left = build(l, root_index-1);
        return root;
    } 
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        io.insert(io.end(), inorder.begin(), inorder.end());
        po.insert(po.end(), postorder.begin(), postorder.end());
        int n = postorder.size();
        poi = n-1;
        for (int i=0; i<n; ++i)
            node_index[inorder[i]] = i;
        return build(0, n-1);
    }
};