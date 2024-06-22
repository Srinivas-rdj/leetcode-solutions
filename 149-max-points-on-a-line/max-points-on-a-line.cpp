class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        vector<vector<int>> lines;
        for(int i=0;i<p.size();i++){
            int x1=p[i][0],y1=p[i][1];
            for(int j=i+1;j<p.size();j++){
                int x2=p[j][0],y2=p[j][1];
                lines.push_back({y1-y2,x2-x1,x2*y1-y2*x1});
            }
        }
        int ans=1;
        for(int i=0;i<lines.size();i++){
            int cnt=0,a=lines[i][0],b=lines[i][1],c=lines[i][2];
            for(int j=0;j<p.size();j++){
                int x=p[j][0],y=p[j][1];
                if(a*x+b*y==c) cnt++;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};