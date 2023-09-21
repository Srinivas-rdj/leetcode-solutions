class Solution {
public:
    vector<int> par;
    int findpar(int x){
        if(par[x]==x) return x;
       return  par[x]=findpar(par[x]);
    }
    bool unionnodes(int x,int y){
        int p1=findpar(x),p2=findpar(y);
        if(p1==p2) return 1;
        par[p1]=p2;
        return false;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> v;
        par.resize(points.size());
        for(int i=0;i<points.size();i++){
            int x=points[i][0],y=points[i][1];
            for(int j=i+1;j<points.size();j++){
                int x1=points[j][0],y1=points[j][1];
                int d=abs(x1-x)+abs(y1-y);
                v.push_back({d,i,j});
            }
        }
        for(int i=0;i<points.size();i++) par[i]=i;
        sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(!unionnodes(v[i][1],v[i][2])){
                ans+=v[i][0];
            }
        }
        return ans;
    }
};