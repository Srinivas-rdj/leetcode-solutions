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
    int paths(TreeNode* root,int x){
        int y=x^(1<<(root->val-1));
        int ans=0,cnt=0;
        for(int i=0;i<9;i++){
            if((y>>i)&1) cnt++;
        }
        if(cnt<=1&&root->left==NULL&&root->right==NULL) ans++;
        if(root->left!=NULL) ans+=paths(root->left,y);
        if(root->right!=NULL) ans+=paths(root->right,y);
        return ans;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        return paths(root,0);
    }
};