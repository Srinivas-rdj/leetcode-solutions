class Solution {
public:
    static const int maxn=500;
    int lcs(int i,int j,string& s,string& t,int n,int dp[][maxn]){
        if(i==s.size()||j==t.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j]=1+lcs(i+1,j+1,s,t,n,dp);
        return dp[i][j]=max(lcs(i+1,j,s,t,n,dp),lcs(i,j+1,s,t,n,dp));
    }
    int minInsertions(string s) {
        string t=s;
        reverse(s.begin(),s.end());
        int dp[maxn][maxn];
        memset(dp,-1,sizeof(dp));
      return  s.size()-lcs(0,0,s,t,s.size(),dp);
    }
};