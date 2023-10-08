class Solution {
public:
    int maxproduct(int i,int j,int x,vector<int>& v1,vector<int>& v2,vector<vector<vector<int>>>& dp){
        if(i==v1.size()||j==v2.size()){if(x) return 0;
        return INT_MIN;
        }
        if(dp[i][j][x]!=-1) return dp[i][j][x];
        int ans=INT_MIN;
        ans=max({v1[i]*v2[j]+maxproduct(i+1,j+1,1,v1,v2,dp),maxproduct(i+1,j,x,v1,v2,dp),maxproduct(i,j+1,x,v1,v2,dp)});
        return dp[i][j][x]=ans;
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<vector<int>>> dp(nums1.size(),vector<vector<int>>(nums2.size(),vector<int>(2,-1)));
        return maxproduct(0,0,0,nums1,nums2,dp);
    }
};