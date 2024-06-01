class Solution {
public:
    int countTriplets(vector<int>& arr) {
        map<int,int> val,cnt,prev;
        int ans=0;
        val[0]=0;
        cnt[0]=1;
        prev[0]=0;
        int x=0;
        for(int i=0;i<arr.size();i++){
            x=x^arr[i];
            if(cnt[x]!=0){
                int y=i+1-prev[x];
                val[x]+=y*(cnt[x]-1)+y-1;
                ans+=val[x];
            }
            prev[x]=i+1;
            cnt[x]++;
        }
        return ans;
    }
};