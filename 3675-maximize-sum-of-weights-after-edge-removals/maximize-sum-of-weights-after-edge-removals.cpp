class Solution {
public:
    long long maxsum(int i,int p,int k1,int k,vector<vector<pair<int,int>>>& v,vector<vector<long long>>& dp){
        if(k==0) return 0;
        int b=0;
        if(k1==k) b=1;
        if(dp[i][b]!=-1) return dp[i][b];
        vector<vector<long long>> vec;
        for(auto t:v[i]){
            if(t.first!=p){
                long long x=t.second+maxsum(t.first,i,k-1,k,v,dp);
                long long y=maxsum(t.first,i,k,k,v,dp);
                vec.push_back({x-y,x,y});
            }
        }
        sort(vec.begin(),vec.end());
        int cnt=0;
        long long ans=0;
        for(int j=vec.size()-1;j>=0;j--){
            if(vec[j][0]<=0||cnt==k1){
                ans+=vec[j][2];
                continue;
            }
            ans+=vec[j][1];
            cnt++;
        }
        return dp[i][b]=ans;
    }
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        int n=edges.size()+1;
        vector<vector<pair<int,int>>> v(n);
        vector<vector<long long>> dp(n+1,vector<long long>(2,-1));
        for(auto t:edges){
            v[t[0]].push_back({t[1],t[2]});
            v[t[1]].push_back({t[0],t[2]});
        }
        return maxsum(0,-1,k,k,v,dp);
    }
};