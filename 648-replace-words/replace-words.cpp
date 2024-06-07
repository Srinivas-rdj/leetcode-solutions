class Solution {
public:
    string replaceWords(vector<string>& dict, string s) {
        map<string,int> mp;
        string ans="";
        for(string st:dict) mp[st]++;
        for(int i=0;i<s.size();i++){
            string st="";
            int j=i;
            for(;j<s.size()&&s[j]!=' ';j++){
                st+=s[j];
                if(mp[st]) break;
            }
            while(j<s.size()&&s[j]!=' ') j++;
            i=j;
            ans+=st+" ";
        }
        ans.pop_back();
        return ans;
    }
};