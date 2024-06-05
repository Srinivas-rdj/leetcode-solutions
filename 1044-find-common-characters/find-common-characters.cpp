class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
      vector<int> prev(26,0),v(26,0);
      string st=words[0];
      for(char c:st) prev[c-'a']++;
      for(int i=1;i<words.size();i++){
        string s=words[i];
        for(char c:s) v[c-'a']++;
        for(int j=0;j<26;j++){
            prev[j]=min(prev[j],v[j]);
            v[j]=0;
        }
      }

      vector<string> ans;
      for(int i=0;i<26;i++){
        int x=prev[i];
        while(x--){
            string s;
            s.push_back((char)i+'a');
            ans.push_back(s);
        }
      }
        return ans;
    }
};