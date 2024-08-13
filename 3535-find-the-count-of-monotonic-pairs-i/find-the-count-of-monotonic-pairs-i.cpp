class Solution {
public:
    static const int m=1e9+7;
    int cnt(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i==nums.size()) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        int xp=j,yp=INT_MAX;
        if(i!=0) yp=nums[i-1]-j;
        for(int k=j;k<=nums[i];k++){
            int x=k,y=nums[i]-k;
            if(yp<y) continue;
            ans=(ans+cnt(i+1,k,nums,dp))%m;
        }
        return dp[i][j]=ans;
    }
    int countOfPairs(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(51,-1));
        return cnt(0,0,nums,dp);
    }
};