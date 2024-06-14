class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int maxi=nums[0],ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]<=maxi){
                ans+=maxi-nums[i]+1;
                nums[i]=maxi+1;
            }
            maxi=max(maxi,nums[i]);
        }
        return ans;
    }
};