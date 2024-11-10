#define ll long long int
class Solution {
public:
    int sumOfGoodSubsequences(vector<int>& nums) {
        // no of subsequences 
        // sum of subsequences 
        // sum for 1 
        // sum for 2 
        ll mod = 1e9+7;
        ll n = nums.size();
        vector<ll> ways(n,0);
        vector<ll> sum(n,0);
        map<ll,ll> nways;
        map<ll,ll> nsum;
        for(ll i = 0;i<n;i++){
            ways[i] = ((nways[nums[i]-1]+nways[nums[i]+1])%mod+1)%mod;
            sum[i] = (nsum[nums[i]-1]+nsum[nums[i]+1])%mod;
            sum[i] = (sum[i]+nums[i])%mod;
            sum[i] = sum[i] +(((nways[nums[i]-1]+nways[nums[i]+1])%mod)*nums[i])%mod;
            nways[nums[i]]=(nways[nums[i]]+ways[i])%mod;
            nsum[nums[i]]=(nsum[nums[i]]+sum[i])%mod;
            // cout<< ways[i] << " "<< sum[i]<< " " << nways[nums[i]] << " " << nsum[nums[i]]<<endl; 
        }
        ll ans = 0;
        for(auto j : nsum) ans =(ans + j.second)%mod;
        return ans;
    }
};