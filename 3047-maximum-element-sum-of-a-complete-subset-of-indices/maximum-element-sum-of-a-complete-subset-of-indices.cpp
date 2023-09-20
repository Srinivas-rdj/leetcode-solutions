class Solution {
public:
bool isperfect(int i){
    return sqrt(i)==(int)sqrt(i);
}
    long long maximumSum(vector<int>& nums) {
        long long ans=INT_MIN;
        unordered_map<int,long long> mp;
        for(int i=1;i<=nums.size();i++){
            for(int j=1;j*j<=i;j++){
                if(i%j==0){
                    if(isperfect(j)){
                        mp[i/j]+=nums[i-1];
                        ans=max(ans,mp[i/j]);
                    }
                    if(j!=i/j&&isperfect(i/j)){
                        mp[j]+=nums[i-1];
                        ans=max(ans,mp[j]);
                    }
                }
            }
        }
        return ans;
    }
};