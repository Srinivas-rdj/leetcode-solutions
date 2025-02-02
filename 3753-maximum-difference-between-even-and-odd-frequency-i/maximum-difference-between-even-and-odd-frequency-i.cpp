class Solution {
public:
    int maxDifference(string s) {
        vector<int> v(26,0);
        for(char c:s) v[c-'a']++;
        int ev=101,od=0;
        for(int i:v){
            if(i%2) od=max(od,i);
            else if(i!=0) ev=min(ev,i);
        }
        if(ev==101) ev=0;
        return od-ev;
    }
};