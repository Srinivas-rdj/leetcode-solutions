class Solution {
public:
    bool ispos(string& s,string& t){
        int x=0;
        for(int i=0;i<s.size();i++){
            if(s[i]!=t[i]) x++;
        }
        return x==1;
    }
    vector<string> getWordsInLongestSubsequence(int n, vector<string>& words, vector<int>& groups) {
        int ans=0,maxi=1;
        vector<int> dp(n,1);
        vector<int> par(n,-1);
        for(int i=0;i<n;i++) par[i]=i;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(groups[j]!=groups[i]&&words[j].size()==words[i].size()&&ispos(words[i],words[j])){
                   if(dp[i]<dp[j]+1){
                       dp[i]=dp[j]+1;
                       par[i]=j;
                   }
                }
            }
         if(dp[i]>maxi){ ans=i; 
         maxi=dp[i];
         } 
        }
        vector<string> v;
        while(par[ans]!=ans){
            v.push_back(words[ans]);
            ans=par[ans];
        }
        v.push_back(words[ans]);
        reverse(v.begin(),v.end());
        return v;
    }
};