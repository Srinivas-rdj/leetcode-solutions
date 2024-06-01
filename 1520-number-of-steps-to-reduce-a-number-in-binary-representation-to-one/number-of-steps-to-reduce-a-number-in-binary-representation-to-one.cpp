class Solution {
public:
    int numSteps(string s) {
        int ans=0,i=0;
        reverse(s.begin(),s.end());
        while(i<s.size()){
            if(i!=s.size()-1&&s[i]=='1'){ 
                // cout<<i<<" "<<s[i]<<"\n";
                ans+=2;
                i++;
                while(i<s.size()&&s[i]!='0'){
                    
                    i++;
                    ans++;
                }
                if(i!=s.size())  s[i]='1';
            }
            else if(s[i]=='0'){
                 while(i<s.size()&&s[i]!='1'){
                   
                    i++;
                    ans++;
                }
            }
            else i++;
            // cout<<i<<" "<<ans<<"\n";
        }
        return ans;
    }
};