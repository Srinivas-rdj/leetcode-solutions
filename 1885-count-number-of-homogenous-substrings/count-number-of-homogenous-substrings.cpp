class Solution {
public:
    int countHomogenous(string s) {
        int ans=0,mod=1e9+7;
        for(int i=0;i<s.size();){
            int j=i;
            while(j<s.size()&&s[i]==s[j]) j++;
            long long x=j-i;
            i=j;
            x=(x*((x+1)%mod))%mod;
            x=x/2;
            ans=(ans+x)%mod;
        }
        return ans;
    }
};