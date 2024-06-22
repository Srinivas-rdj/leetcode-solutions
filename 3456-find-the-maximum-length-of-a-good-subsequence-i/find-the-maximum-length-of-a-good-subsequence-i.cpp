class Solution {
public:
    int maxlen(int i,int p,int k_l,vector<int>& nums,int k,vector<vector<vector<int>>>& dp){
        if(i==nums.size()) return 0;
        if(dp[i][p+1][k_l]!=-1) return dp[i][p+1][k_l];
        int ans=0;
        ans=max(ans,maxlen(i+1,p,k_l,nums,k,dp));
        if(p==-1) ans=max(ans,1+maxlen(i+1,i,k_l,nums,k,dp));
        else if(nums[i]==nums[p]) ans=max(ans,1+maxlen(i+1,p,k_l,nums,k,dp));
        else if(k_l<k) ans=max(ans,1+maxlen(i+1,i,k_l+1,nums,k,dp));
        return dp[i][p+1][k_l]=ans;
    }
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return maxlen(0,-1,0,nums,k,dp);
    }
};