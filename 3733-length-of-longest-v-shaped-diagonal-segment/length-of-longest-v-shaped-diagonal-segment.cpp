class Solution {
public:
    int longlen(int i,int j,int b,int d,vector<vector<int>>& g,vector<vector<vector<vector<int>>>>& dp){
        int n=g.size(),m=g[0].size(),ans=1,p=g[i][j];
        if(g[i][j]==1) return 0;
        if(dp[i][j][b][d]!=-1) return dp[i][j][b][d];
        // cout<<i<<" "<<j<<"\n";
        if(d==0){
            if(b==0&&i-1>=0&&j+1<m&&p!=g[i-1][j+1]) ans=max(ans,1+longlen(i-1,j+1,1,2,g,dp));
            if(i-1>=0&&j-1>=0&&p!=g[i-1][j-1]) ans=max(ans,1+longlen(i-1,j-1,b,0,g,dp));
        }
        if(d==1){
            // cout<<"yep\n";
            if(b==0&&i+1<n&&j-1>=0&&p!=g[i+1][j-1]) ans=max(ans,1+longlen(i+1,j-1,1,3,g,dp));
            if(i+1<n&&j+1<m&&p!=g[i+1][j+1]) ans=max(ans,1+longlen(i+1,j+1,b,1,g,dp));
        }
        if(d==2){
            if(b==0&&i+1<n&&j+1<m&&p!=g[i+1][j+1]) ans=max(ans,1+longlen(i+1,j+1,1,1,g,dp));
            if(i-1>=0&&j+1<m&&p!=g[i-1][j+1]) ans=max(ans,1+longlen(i-1,j+1,b,2,g,dp));
        }
        if(d==3){
            if(b==0&&i-1>=0&&j-1>=0&&p!=g[i-1][j-1]) ans=max(ans,1+longlen(i-1,j-1,1,0,g,dp));
            if(i+1<n&&j-1>=0&&p!=g[i+1][j-1]) ans=max(ans,1+longlen(i+1,j-1,b,3,g,dp));
        }
        return dp[i][j][b][d]=ans;
    }
    int lenOfVDiagonal(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();
       vector<pair<int,int>> v;
       for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==1) v.push_back({i,j});
            }
       }
       vector<vector<vector<vector<int>>>> dp(n,vector<vector<vector<int>>>(m,vector<vector<int>>(2,vector<int>(4,-1))));
       if(v.size()==0) return 0;
       int ans=1;
       for(pair<int,int> p:v){
        int x=p.first,y=p.second;
        cout<<x<<" "<<y<<"B\n";
        if(x-1>=0&&y-1>=0&&g[x-1][y-1]==2) ans=max(ans,1+longlen(x-1,y-1,0,0,g,dp));
        if(x+1<n&&y+1<m&&g[x+1][y+1]==2) ans=max(ans,1+longlen(x+1,y+1,0,1,g,dp));
        if(x-1>=0&&y+1<m&&g[x-1][y+1]==2) ans=max(ans,1+longlen(x-1,y+1,0,2,g,dp));
        if(x+1<n&&y-1>=0&&g[x+1][y-1]==2) ans=max(ans,1+longlen(x+1,y-1,0,3,g,dp));
        cout<<ans<<"\n";
       }
       return ans;
    }
};