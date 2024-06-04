class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int maxi=0,ans=0;
        for(char c : s){
            mp[c]++;
        }
        bool f=0;
        for(pair<char,int> p: mp) {
            if(p.second%2) {
                f=1;
                ans+=p.second-1;
            }
            else ans+=p.second;
        }
      if(f)  return ans+1;
      return ans;
    }
};