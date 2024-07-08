class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        vector<int> prev(n,0);
        map<int,int> mp;
        for(int i=0;i<nums.size();i++){
          if(mp[nums[i]]!=0)  prev[i]=mp[nums[i]];
            mp[nums[i]]=i+1;
        } 
        vector<int> v(k+1,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            dp[i+1][0]=dp[prev[i]][0]+1;
            ans=max(dp[i+1][0],ans);
            cout<<prev[i]<<" "<<dp[prev[i]][0]<<" "<<dp[i+1][0]<<"\n";
            vector<int> p=v;
                    if(dp[i+1][0]>dp[v[0]+1][0]) p[0]=i;
            for(int j=1;j<=k;j++){
                    int x=dp[prev[i]][j];
                    int y=dp[v[j-1]+1][j-1];
                    // cout<<v[j-1]<<"\n";
                    // cout<<i<<" "<<j<<" "<<x<<" "<<y<<"\n";
                    dp[i+1][j]=max(x,y)+1;
                    ans=max(ans,dp[i+1][j]);
                    if(dp[i+1][j]>dp[v[j]+1][j]) p[j]=i;
                    // cout<<i<<" "<<j<<" "<<dp[i+1][j]<<"\n";
            }
            v=p;
        }
        return ans;
    }
};