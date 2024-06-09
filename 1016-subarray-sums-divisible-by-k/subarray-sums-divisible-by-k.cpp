class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
       vector<int> mp(k,0);
        int ans=0;
        mp[0]++;
        for(int i=0;i<nums.size();i++){
         if(i!=0)  nums[i]=(nums[i]+nums[i-1])%k;
            nums[i]=(nums[i]%k+k)%k;
           ans+=mp[nums[i]];
           mp[nums[i]]++;
        }
        return ans;
    }
};