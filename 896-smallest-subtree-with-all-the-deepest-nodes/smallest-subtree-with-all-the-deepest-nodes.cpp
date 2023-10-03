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
    TreeNode* ans;
    int dfs1(TreeNode* root){
        int x=0,y=0;
        if(root->left!=NULL) x=dfs1(root->left);
        if(root->right!=NULL) y=dfs1(root->right);
        return max(x,y)+1;
    }
    int  dfs2(TreeNode* root,int d){
        if(d==1){
            ans=root;
            return 1;
        }
        int x=0,y=0;
        if(root->left!=NULL) x=dfs2(root->left,d-1);
        if(root->right!=NULL) y=dfs2(root->right,d-1);
        if(x&&y) ans=root;
        return x||y;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxd=dfs1(root);
        dfs2(root,maxd);
        return ans;
    }
};