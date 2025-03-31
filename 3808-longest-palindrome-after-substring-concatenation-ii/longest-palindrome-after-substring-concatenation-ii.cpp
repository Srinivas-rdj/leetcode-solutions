class Solution {
public:
    void palindrome_length(int i,int j,vector<int>& p,string& s,int b){
        while(i>=0&&j<s.size()&&s[i]==s[j]){
          if(b)  p[i]=max(p[i],j-i+1);
          else p[j]=max(p[j],j-i+1);
            i--;
            j++;
        }
    }
    int longestPalindrome(string s, string t) {
        int n=s.size(),m=t.size();
        if(s==t) return n+m;
        int ans=0;
        vector<int> si(n,0),ps(n,0),pt(m,0),sj(m,0);
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            palindrome_length(i,i,ps,s,1);
            if(i!=n-1) palindrome_length(i,i+1,ps,s,1);
        }
        for(int i=0;i<m;i++){
            palindrome_length(i,i,pt,t,0);
            if(i!=m-1) palindrome_length(i,i+1,pt,t,0);
        }
        reverse(t.begin(),t.end());
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(s[i]==t[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                }
                si[i]=max(si[i],dp[i+1][j+1]);
                sj[m-j-1]=max(sj[m-j-1],dp[i+1][j+1]);
            }
        }
        // for(int i:ps) cout<<i<<" ";
        // cout<<"\n";
        // for(int i:pt) cout<<i<<" ";
        // cout<<"\n";
        // for(int i:si) cout<<i<<" ";
        // cout<<"\n";
        // for(int i:sj) cout<<i<<" ";
        for(int i=0;i<n;i++){
            int x=0;
            if(i!=n-1) x=ps[i+1];
            ans=max({ans,x+2*si[i],ps[i]});
        }
        for(int i=0;i<m;i++){
            int x=0;
            if(i!=0) x=pt[i-1];
            ans=max({ans,x+2*sj[i],pt[i]});
        }
        return ans;
    }
};