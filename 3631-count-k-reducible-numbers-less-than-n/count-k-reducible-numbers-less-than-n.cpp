int m=1e9+7;
class Solution {
public:
    int solve(int i,int cnt,int b,string& s,int k,vector<int>& dp,vector<vector<vector<int>>>& v){
        if(i==s.size()){
            // cout<<cnt<<" "<<dp[cnt]<<"\n";

            int x= (dp[cnt]+1<=k)&&(b&&(cnt>0));
            // cout<<x;
            return x;
        }
        if(v[i][cnt][b]!=-1) return v[i][cnt][b];
        if(s[i]=='1'){
            return v[i][cnt][b]=(solve(i+1,cnt,1,s,k,dp,v)+solve(i+1,cnt+1,b,s,k,dp,v))%m;
        }
        int ans=0;
        ans=(ans+solve(i+1,cnt,b,s,k,dp,v))%m;
        if(b){
            ans=(ans+solve(i+1,cnt+1,b,s,k,dp,v))%m;
        }
        return v[i][cnt][b]=ans;
    }
    int countKReducibleNumbers(string s, int k) {
        vector<int> dp(s.size()+1,0);
        for(int i=2;i<=s.size();i++){
            dp[i]=1+dp[__builtin_popcount(i)];
            // cout<<dp[i]<<" \n";
        }
        vector<vector<vector<int>>> v(s.size()+1,vector<vector<int>>(s.size()+1,vector<int>(2,-1)));
        return solve(0,0,0,s,k,dp,v);
    }
};