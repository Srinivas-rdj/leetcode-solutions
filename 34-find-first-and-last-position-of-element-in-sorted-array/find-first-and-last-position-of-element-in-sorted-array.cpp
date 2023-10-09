class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2,-1);
        int x=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(x!=nums.size()&&nums[x]==target) ans[0]=x;
        else return ans;
        x=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        ans[1]=x-1;
        return ans;
    }
};