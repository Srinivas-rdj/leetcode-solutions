class Solution {
public:
    long long countSubstrings(string s) {
        vector<int> v3(3,0),v7(7,0),v9(9,0);
        long long ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='2'||s[i]=='1'||s[i]=='5') ans+=i+1;
            int c=(s[i]-'0');
            int x=c%3,y=c%7,z=c%9;
            // cout<<x<<"\n";
            vector<int> v13=v3,v17=v7,v19=v9;
            for(int i=0;i<3;i++) v3[(i+x)%3]=v13[i];
            for(int i=0;i<7;i++) v7[(3*i+y)%7]=v17[i];
            for(int i=0;i<9;i++) v9[(i+z)%9]=v19[i];
            v3[x]++;
            v7[y]++;
            v9[z]++;
            if(s[i]=='3'||s[i]=='6') ans+=v3[0];
            if(s[i]=='9') ans+=v9[0];
            if(s[i]=='7') ans+=v7[0];
            if(s[i]=='4'){
                if(i==0) ans++;
                else if((s[i-1]-'0')%2==0) ans+=i+1;
                else ans++;
            }
            if(s[i]=='8'){
                if(i==0) ans++;
                if(i>0){
                    if((s[i-1]-'0')%4==0) ans+=2;
                    else ans++;
                }
                if(i>1){
                    int x=(s[i-2]-'0')*10+(s[i-1]-'0');
                    if(x%4==0) ans+=(i-1);
                }
            }
            // cout<<s[i]<<" "<<ans<<"\n";
        }
        return ans;
    }
};