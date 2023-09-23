class Solution {
public:
    int mincost(int i,int j,int t,int k,vector<int>& pre, vector<vector<vector<int>>>& dp){
        if(t==k){
            if(j-i+1==t) return pre[j+1]-pre[i];
        }
        if(t==1){
            if(i==j) return 0;
            if(j-i+1==k) return pre[j+1]-pre[i];
            return mincost(i,j,k,k,pre,dp); 
        }
        if(j-i+1<t) return 1e7;
        if(dp[i][j][t]!=-1) return dp[i][j][t];
        int ans=1e7,s=pre[j+1]-pre[i];
        int y=mincost(i+1,j,t-1,k,pre,dp);
       if(t==k) ans=min(ans,s+y);
       else  ans=min(ans,y);
        for(int l=i+k-1;l<j;l++){
            int x=mincost(i,l,k,k,pre,dp)+mincost(l+1,j,t-1,k,pre,dp);
            if(t==k) ans=min(ans,s+x);
            else ans=min(ans,x);
        }
        return dp[i][j][t]=ans;
    }
    int mergeStones(vector<int>& v, int k) {
        int n=v.size();
        if(n==1) return 0;
        vector<int> pre(n+1,0);
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+v[i-1];
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int x= mincost(0,n-1,k,k,pre,dp);
        if(x>=1e7) return -1;
        return x;
    }
};