class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        unordered_map<char,int> mp;
        for(char c:s) mp[c]++;
        int x=0;
        for(int i=0;i<s.size();i++){
            if((x>>(s[i]-'a'))&1) {
                mp[s[i]]--;
                continue;
            }
            while(!st.empty()&&st.top()>s[i]&&mp[st.top()]>0) {
                x=x^(1<<(st.top()-'a'));
                st.pop();}
            st.push(s[i]);
            x=x|(1<<(s[i]-'a'));
            mp[s[i]]--;
        }
        string ans="";
        while(!st.empty()){
            char c=st.top();
            ans+=c;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};