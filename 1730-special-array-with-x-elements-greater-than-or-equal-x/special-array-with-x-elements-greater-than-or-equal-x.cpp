class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<=nums.size();i++){
            int x=lower_bound(nums.begin(),nums.end(),i)-nums.begin();
            int n=nums.size()-x;
            if(n==i) return i;
        }
        return -1;
    }
};