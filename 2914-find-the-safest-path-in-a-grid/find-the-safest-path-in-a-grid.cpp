class Solution {
public:
 vector<int> a={1,0,-1,0},b={0,1,0,-1};
    bool ispos(int i,int j,int n){
        if(i==n||j==n||i<0||j<0) return false;
        return true;
    }
    void bfs(vector<vector<int>>& v,int n,vector<vector<int>>& grid){
         queue<vector<int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    v[i][j]=0;
                    q.push({0,i,j});
                }
            }
        }
        while(!q.empty()){
            int d=q.front()[0],x=q.front()[1],y=q.front()[2];
            q.pop();
            for(int i=0;i<4;i++){
                if(ispos(x+a[i],y+b[i],n)&&v[x+a[i]][y+b[i]]==-1){
                    v[x+a[i]][y+b[i]]=d+1;
                    q.push({d+1,x+a[i],y+b[i]});
                }
            }
        }
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> v(n,vector<int>(n,-1)),dist(n,vector<int>(n,-1));
       bfs(v,n,grid);
       priority_queue<vector<int>> pq;
       pq.push({v[0][0],0,0});
       dist[0][0]=v[0][0];
       while(!pq.empty()){
           int d=pq.top()[0],x=pq.top()[1],y=pq.top()[2];
           pq.pop();
           if(dist[x][y]<d) continue;
           for(int i=0;i<4;i++){
               int x1=x+a[i],y1=y+b[i];
               if(ispos(x1,y1,n)){
                   if(min(d,v[x1][y1])>dist[x1][y1]){
                       dist[x1][y1]=min(d,v[x1][y1]);
                       pq.push({min(d,v[x1][y1]),x1,y1});
                   }
               }
           }
       }
       return dist[n-1][n-1];
    }
};