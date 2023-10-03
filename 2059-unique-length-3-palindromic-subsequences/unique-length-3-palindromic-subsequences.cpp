class Solution {
public:
    int countPalindromicSubsequence(string s) {
       vector<pair<int,int>> v(26,{-1,-1});
       for(int i=0;i<s.size();i++){
           if(v[s[i]-'a'].first==-1) v[s[i]-'a'].first=i;
           v[s[i]-'a'].second=i;
       } 
       int ans=0;
       for(int i=0;i<26;i++){
           if(v[i].first!=-1){
           int cnt=0,x=v[i].first,y=v[i].second;
            vector<int> v1(26,0);
            for(int j=x+1;j<y;j++){
                if(v1[s[j]-'a']==0){
                    cnt++;
                    v1[s[j]-'a']++;
                }
            }
            ans+=cnt;
       }
       }
       return ans;
    }
};