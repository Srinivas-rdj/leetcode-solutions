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
    pair<int,int> cntsubtree(TreeNode* root,int &cnt){
        if(root==NULL) return {0,0};
        pair<int,int> p1=cntsubtree(root->left,cnt),p2=cntsubtree(root->right,cnt);
        int s=p1.first+p2.first+root->val,n=p1.second+p2.second+1;
        if(s/n==root->val) cnt++;
        return {s,n};
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        cntsubtree(root,cnt);
        return cnt;
    }
};