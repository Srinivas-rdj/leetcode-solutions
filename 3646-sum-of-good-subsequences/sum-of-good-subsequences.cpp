#define ll long long
int m=1e9+7;
class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp,mp1,mp2;
        vector<pair<int,int>> dp(n,{0,0});
        ll ans=0;
        for(int i=n-1;i>=0;i--){
            ll x=0,cnt=1;
            if(mp[nums[i]+1]!=0){
                x=(x+dp[mp[nums[i]+1]].first)%m;
                cnt=(cnt+dp[mp[nums[i]+1]].second)%m;
            }
             if(mp[nums[i]-1]!=0){
                x=(x+dp[mp[nums[i]-1]].first)%m;
                cnt=(cnt+dp[mp[nums[i]-1]].second)%m;
            }
            x=((cnt*nums[i])%m+x)%m;
            ans=(ans+x)%m;
             if(mp[nums[i]]!=0){
                x=(x+dp[mp[nums[i]]].first)%m;
                cnt=(cnt+dp[mp[nums[i]]].second)%m;
            }
            dp[i].first=x;
            dp[i].second=cnt;
            mp[nums[i]]=i;
        }
        return ans;
    }
};