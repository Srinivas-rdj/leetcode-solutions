class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0,maxdiff=0,maxval=nums[0];
        for(int i=0;i<nums.size();i++){
                ans=max(ans,nums[i]*maxdiff);
                maxdiff=max(maxdiff,maxval-nums[i]);
                maxval=max(maxval,1LL*nums[i]);
        }
        return ans;
    }
};