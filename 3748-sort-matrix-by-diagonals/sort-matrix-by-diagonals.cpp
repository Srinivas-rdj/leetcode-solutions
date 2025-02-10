class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& v) {
        int n=v.size();
        vector<vector<int>> ans(n,vector<int>(n));
            for(int j=1;j<n;j++){
                vector<int> vec;
                int i1=0,j1=j;
                while(i1<n&&j1<n){
                    vec.push_back(v[i1][j1]);
                    i1++;
                    j1++;
                }
                sort(vec.begin(),vec.end());
                i1=0;
                j1=j;
                int k=0;
                while(i1<n&&j1<n){
                    ans[i1][j1]=vec[k];
                    i1++;
                    j1++;
                    k++;
                }
            }
            for(int j=0;j<n;j++){
                vector<int> vec;
                int i1=j,j1=0;
                while(i1<n&&j1<n){
                    vec.push_back(v[i1][j1]);
                    i1++;
                    j1++;
                }
                sort(vec.begin(),vec.end(),greater<int>());
                i1=j;
                j1=0;
                int k=0;
                while(i1<n&&j1<n){
                    ans[i1][j1]=vec[k];
                    i1++;
                    j1++;
                    k++;
                }
            }
            return ans;
    }
};