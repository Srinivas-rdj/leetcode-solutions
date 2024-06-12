class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> mat(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) mat[i][j]=matrix[i][j]-'0';
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) continue;
                mat[i][j]+=mat[i+1][j];
            }
        }
        vector<vector<int>> pre(n,vector<int>(m,0)),suff(n,vector<int>(m,0));
        for(int i=n-1;i>=0;i--){
            stack<int> st,st1;
            for(int j=0;j<m;j++){
                while(!st.empty()&&mat[i][st.top()]>=mat[i][j]) st.pop();
                if(st.empty()) pre[i][j]=-1;
                else pre[i][j]=st.top();
                st.push(j);
            }
            for(int j=m-1;j>=0;j--){
                while(!st1.empty()&&mat[i][st1.top()]>=mat[i][j]) st1.pop();
                if(st1.empty()) suff[i][j]=m;
                else suff[i][j]=st1.top();
                st1.push(j);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
            {
                cout<<mat[i][j]<<" "<<suff[i][j]<<" "<<pre[i][j]<<"\n";
                ans=max(ans,mat[i][j]*(suff[i][j]-pre[i][j]-1));
            }
        }
        return ans;
    }
};