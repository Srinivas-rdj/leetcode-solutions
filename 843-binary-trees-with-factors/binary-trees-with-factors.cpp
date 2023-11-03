class Solution {
public:
unordered_map<int,int> mp;
map<int,int> mp1;
int mod=1e9+7;
    int cnttrees(int n){
        if(mp1[n]!=0) return mp1[n];
        int ans=1;
        for(int i=2;i*i<=n;i++){
            if(n%i==0&&mp[i]>0&&mp[n/i]>0){
                if(i!=n/i) ans=(ans*1LL+(2*1LL*(cnttrees(i)*1LL*cnttrees(n/i))%mod)%mod)%mod;
                else ans=(ans*1LL+(cnttrees(i)*1LL*cnttrees(n/i))%mod)%mod;
            }
        }
        return mp1[n]=ans;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        for(int i:arr) mp[i]++;
        int ans=0;

        for(int i=0;i<arr.size();i++){
            ans=(ans*1LL+cnttrees(arr[i]))%mod;
            cout<<ans<<"\n";
        }
        return ans;
    }
};