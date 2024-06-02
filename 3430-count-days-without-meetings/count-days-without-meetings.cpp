class Solution {
public:
    int countDays(int days, vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        int ans=0,end=0;
        for(vector<int> vec:v){
            if(vec[0]<=end){
                end=max(end,vec[1]);
                continue;
            }
            else{
                ans+=vec[0]-end-1;
                end=max(end,vec[1]);
            }
        }
        if(end<=days) ans+=days-end;
        return ans;
    }
};