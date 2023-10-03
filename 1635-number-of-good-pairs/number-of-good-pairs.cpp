class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> v(101,0);
        int ans=0;
        for(int i:nums){
            ans+=v[i];
            v[i]++;
        }
        return ans;
    }
};