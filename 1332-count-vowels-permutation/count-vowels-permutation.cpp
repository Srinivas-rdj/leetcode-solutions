class Solution {
public:
int mod=1e9+7;
void print(vector<vector<int>>& v){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }
}
vector<vector<int>> id={{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{0,0,0,0,1}};
    vector<vector<int>> mult(vector<vector<int>> v1,vector<vector<int>> v2){
        vector<vector<int>> v(5,vector<int>(5,0));
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                for(int k=0;k<5;k++){
                    v[i][j]=(v[i][j]+(v1[i][k]*1LL*v2[k][j])%mod)%mod;
                }
            }
        }
        return v;
    }
    vector<vector<int>> binexp(vector<vector<int>> v,int n){
        if(n==0) return id;
        if(n%2) return mult(v,binexp(mult(v,v),n/2));
        return binexp(mult(v,v),n/2);
    }
    int countVowelPermutation(int n) {
        vector<vector<int>> v={{0,1,0,0,0},{1,0,1,0,0},{1,1,0,1,1},{0,0,1,0,1},{1,0,0,0,0}};
       v= binexp(v,n-1);
        int ans=0;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++) ans=(ans+v[i][j])%mod;
        }
        return ans;
    }
};