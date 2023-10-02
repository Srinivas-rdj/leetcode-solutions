class Solution {
public:
int b=51;
int mod=1e9+7;
vector<int> hash,powb;
    int maxops(int i,string& s,vector<int>& dp){
        if(i==s.size()) return 0;
        if(dp[i]!=-1) return dp[i];
        if(i==s.size()-1) return dp[i]=1;
        int n=(s.size()-i)/2;
        int ans=1;
        while(n){
            if(((((hash[i+n]-hash[i]+mod)%mod)*1LL*powb[i+n+1])%mod)==(((hash[i+2*n]-hash[i+n]+mod)%mod)*1LL*powb[i+1])%mod){
                 ans=max(ans,1+maxops(i+n,s,dp));
            }
            n--;
        }
        return dp[i]=ans;
    }
    int deleteString(string s) {
        vector<int> dp(s.size(),-1);
        hash.resize(s.size()+1,0);
        long long p=b;
        hash[1]=(s[0]-'a'+1);
        powb.resize(s.size()+1,1);
        powb[1]=1;
        for(int i=2;i<=s.size();i++){
            hash[i]=((((s[i-1]-'a'+1LL)*p)%mod)+hash[i-1])%mod;
            powb[i]=p;
            p=(p*b)%mod;
        }
        return maxops(0,s,dp);
    }
};