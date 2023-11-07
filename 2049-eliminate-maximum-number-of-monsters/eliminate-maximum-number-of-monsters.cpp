class Solution {
public:
    int eliminateMaximum(vector<int>& d, vector<int>& s) {
        vector<double> v;
        for(int i=0;i<d.size();i++){
            v.push_back((d[i]*1.0)/s[i]);
        }
        sort(v.begin(),v.end());
        int cnt=0,ans;
        for(int i=0;i<d.size();i++){
            if(v[i]>cnt) {ans++;
            cnt++; }
            else break;
        }
        return ans;
    }
};