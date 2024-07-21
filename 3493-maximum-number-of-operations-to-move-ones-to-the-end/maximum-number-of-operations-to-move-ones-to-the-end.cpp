class Solution {
public:
    int maxOperations(string s) {
        int cnt=0,x=0;
        for(int i=0;i<s.size();){
            if(s[i]=='1') {i++; x++;
            continue;}
            while(s[i]=='0') {
                i++;
            }
            cnt+=x;
        }
        return cnt;
    }
};