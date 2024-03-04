class Solution {
public:
    int bagOfTokensScore(vector<int>& v, int p) {
        int l=0,r=v.size()-1;
        int maxscore=0,s=0;
        sort(v.begin(),v.end());
        while(l<=r){
            if(p<v[l]&&s>0){
                s--;
                p+=v[r];
                r--;
            }
            else if(p>=v[l]){
                s++;
                p-=v[l];
                l++;
            }
            else break;
            maxscore=max(maxscore,s);
        }
        return maxscore;
    }
};