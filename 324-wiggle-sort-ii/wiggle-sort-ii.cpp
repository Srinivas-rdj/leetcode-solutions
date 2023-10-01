class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size(),x=(n+1)/2;
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=0;i<x;i++){
            ans.push_back(nums[x-i-1]);
           if(x+i<n) ans.push_back(nums[n-i-1]);
        }
        nums=ans;
    }
};