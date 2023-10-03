class Solution {
public:
    int destroyTargets(vector<int>& nums, int s) {
        int n=nums.size();
        unordered_map<int,int> mp;
         int maxi=0;
        for(int i=0;i<n;i++){
            mp[nums[i]%s]++;
            maxi=max(mp[nums[i]%s],maxi);
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]%s]==maxi) ans=min(ans,nums[i]);
        }
        return ans;
    }
};