class Solution {
public:
    int mod=1e9+7;
    int dp[51][51][101];
    int numofways(int i,int m,int k,int j,int n,vector<int>& v){
        if(i>n){
        if(k==0) return 1;
        return 0;
        }
        if(dp[i][k][j]!=-1){
             return dp[i][k][j];}
        int ans=0,x=m;
        if(k==0){
            x=j;
        }
        for(int ele=1;ele<=x;ele++){
                v[i]=ele;
            if(ele>j){
                ans=(ans+numofways(i+1,m,k-1,ele,n,v))%mod;
            }
            else ans=(ans+numofways(i+1,m,k,j,n,v))%mod;
        }
        return dp[i][k][j]=ans;
    }
    int numOfArrays(int n, int m, int k) {
        if(k==0) return 0;
        vector<int> ans(n+1);
        ans[0]=-1;
        memset(dp,-1,sizeof(dp));
        return numofways(1,m,k,0,n,ans);
    }
};