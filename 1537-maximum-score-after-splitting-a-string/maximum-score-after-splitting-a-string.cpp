class Solution {
public:
    int maxScore(string s) {
        int x=0,y=0,ans=0;
        for(char c:s){
            if(c-'0') x++;
        }
        for(int i=0;i<s.size()-1;i++){
            char c=s[i];
            if(c-'0') x--;
            else y++;
            ans=max(ans,x+y);
        }
        return ans;
    }
};