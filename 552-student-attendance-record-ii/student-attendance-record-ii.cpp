class Solution {
public:
    int m=1e9+7;
    int recur(int i,int l,int a,int n,vector<vector<vector<int>>>& dp){
        if(i==n) return 1;
        if(dp[i][l][a]!=-1) return dp[i][l][a];
        int s=0;
        s=(s+recur(i+1,0,a,n,dp))%m;
        if(l<2) s=(s+recur(i+1,l+1,a,n,dp))%m;
        if(a<1) s=(s+recur(i+1,0,a+1,n,dp))%m;
        return dp[i][l][a]=s%m;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(3,vector<int>(2,-1)));
        return recur(0,0,0,n,dp);
    }
};