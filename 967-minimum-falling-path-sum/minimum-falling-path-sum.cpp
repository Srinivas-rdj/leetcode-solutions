class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                int x=matrix[i][j];
                matrix[i][j]+=matrix[i-1][j];
                if(j-1>=0 ) matrix[i][j]=min(x+matrix[i-1][j-1],matrix[i][j]);
                if(j+1<matrix.size()) matrix[i][j]=min(x+matrix[i-1][j+1],matrix[i][j]);
          }
        }
        int ans=INT_MAX;
        for(int i=0;i<matrix.size();i++) ans=min(ans,matrix[matrix.size()-1][i]);
        return ans;
    }
};