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
    pair<TreeNode*,int> lca(TreeNode* root){
        pair<TreeNode*,int> left = {NULL,0},right={NULL,0};
        if(root->right!=NULL) {
            right=lca(root->right);
        }
        if(root->left!=NULL) left = lca(root->left);
        if(left.second>right.second) return {left.first,left.second+1};
        else if(right.second>left.second) return {right.first,right.second+1};
        else return {root,right.second+1};
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return lca(root).first;
    }
};