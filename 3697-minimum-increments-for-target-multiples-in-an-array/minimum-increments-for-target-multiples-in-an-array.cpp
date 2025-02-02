class Solution {
public:
    int minscore(int i,int j,vector<int>& v,vector<int>& t,vector<vector<int>>& dp){
        if(j==(pow(2,t.size())-1)) return 0;
        if(i==v.size()) return 1000000;
        if(dp[i][j]!=-1) return dp[i][j];
         int ans=1000000;
        for(int k=0;k<t.size();k++){
            if(!((j>>k)&1)){
                // cout<<i<<" "<<j<<"\n";
                int s=0;
                if(v[i]%t[k]==0) s=0;
                else s=t[k]-(v[i]%t[k]);
                int j1=j;
                for(int k1=0;k1<t.size();k1++){
                    if((v[i]+s)%t[k1]==0) j=(j|(1<<k1));
                }
                ans=min(ans,s+minscore(i+1,j,v,t,dp));
                j=j1;
            }
        }
        ans=min(ans,minscore(i+1,j,v,t,dp));
        return dp[i][j]=ans;
    }
    int minimumIncrements(vector<int>& v, vector<int>& t) {
        vector<int> vec;
        sort(t.begin(),t.end());
        for(int i=t.size()-1;i>=0;i--){
         if(t[i]!=-1) {  vec.push_back(t[i]);
            for(int j=i-1;j>=0;j--){
                if(t[j]!=-1&&(t[i]%t[j])==0) t[j]=-1;
            }
                      }
        }
        vector<vector<int>> dp(v.size(),vector<int>(1<<(vec.size()),-1));
        return minscore(0,0,v,vec,dp);
    }
};