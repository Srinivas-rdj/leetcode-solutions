class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> hash(n,-1);
        vector<int> dp(n,1);
        int maxl=0;
        for(int i=1;i<n;i++){
            int maxi=-1;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(maxi==-1||dp[j]>dp[maxi]){
                        maxi=j;
                    }
                }
            }
            if(maxi!=-1) dp[i]=1+dp[maxi];
            hash[i]=maxi;
            if(dp[i]>dp[maxl]) maxl=i;
        }
        vector<int> v;
        while(maxl!=-1){
                v.push_back(nums[maxl]);
                maxl=hash[maxl];
        }
        reverse(v.begin(),v.end());
        return v;
    }
};