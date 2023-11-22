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
    TreeNode* first=NULL,*second=NULL;
        TreeNode* pre=NULL;
    void traverse(TreeNode* root){
        if(root==NULL) return ;
        traverse(root->left);
        if(pre!=NULL){
            if(pre->val>root->val){
                // cout<<root->val<<"\n";
                if(first!=NULL) second=root;
                else{ first=pre;second=root;}
            }
        }
            pre=root;
        traverse(root->right);
    }
    void recoverTree(TreeNode* root) {
        traverse(root);
        if(second!=NULL){
            int x=second->val;
        second->val=first->val;
        first->val=x;
        }
    }
};