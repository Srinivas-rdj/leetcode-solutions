class Solution {
public:
    int appendCharacters(string s, string t) {
        int l=0,r=0;
        while(l<s.size()&&r<t.size()){
            if(s[l]==t[r]) r++;
            l++;
        }
        return t.size()-r;
    }
};