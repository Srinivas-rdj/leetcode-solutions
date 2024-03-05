class Solution {
public:
    int minimumLength(string s) {
        int l=0,r=s.size()-1;
        while(l!=r&&s[l]==s[r]){
            char c=s[l];
            int l1=l,r1=r;
            while(l<s.size()&&s[l]==c) l++;
            c=s[r];
            while(r>=0&&s[r]==c) r--;
            if(l>r) {
                return 0;
            }
        }
        return r-l+1;
    }
};