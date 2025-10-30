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
vector<int> solve(TreeNode* node,vector<int>& v){
        if(node != NULL){
            solve(node->left,v);
            v.push_back(node->val);
            solve(node->right,v);
        }
        return v;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        return solve(root,v);

    }
};