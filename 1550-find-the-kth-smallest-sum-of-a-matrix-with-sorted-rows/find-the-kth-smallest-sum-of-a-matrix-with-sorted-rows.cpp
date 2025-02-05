class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n=mat.size(),m=mat[0].size(),sum=0;
        set<pair<int,vector<int>>> s;
        vector<int> v(n,0);
        for(int i=0;i<n;i++) sum+=mat[i][0];
        s.insert({sum,v});
        int i=1;
        while(i<k){
            int sum2=(*s.begin()).first;
            v=(*s.begin()).second;
            s.erase({sum2,v});
            for(int j=0;j<n;j++){
               int sum=sum2;
               if(v[j]+1<m){ 
                sum+=mat[j][v[j]+1]-mat[j][v[j]];
               v[j]++;
               s.insert({sum,v});
               v[j]--;
               }
            }
            i++;
        }
        return (*s.begin()).first;
    }
};