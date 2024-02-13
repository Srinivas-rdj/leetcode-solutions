class Solution {
public:
    bool ispalindrome(string& s)
    {
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l]!=s[r]) return 0;
            l++;
            r--;
        }
        return 1;
    }
    string firstPalindrome(vector<string>& words) {
        for(string s : words){
            if(ispalindrome(s)) return s;
        }
        return "";
    }
};