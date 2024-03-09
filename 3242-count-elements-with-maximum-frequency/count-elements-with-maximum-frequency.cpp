class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int cnt=0;
        map<int,int> mp;
        for(int i:nums){
            cnt=max(cnt,++mp[i]);
        }
        int ans=0;
        for(pair<int,int> p:mp){
            if(cnt==p.second)  ans+=cnt;
        }
        return ans;
    }
};