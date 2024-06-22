class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        int cnt=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]>='0'&&s[i]<='9') cnt++;
            else{
                if(cnt>0) cnt--;
                else ans.push_back(s[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};