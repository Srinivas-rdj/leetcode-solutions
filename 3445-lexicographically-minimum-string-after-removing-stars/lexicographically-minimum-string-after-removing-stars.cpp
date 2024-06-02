class Solution {
public:
    struct cmp{
        bool operator()(const pair<char,int>& a,const pair<char,int>& b) const{
        if(a.first>b.first) return 1;
        else if(a.first==b.first&&a.second<=b.second) return 1;
        return 0;
    }
    };
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>,cmp> pq;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                pair<char,int> p=pq.top();
                pq.pop();
                s[p.second]='$';
                continue;
            }
            else{
                pq.push({s[i],i});
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'&&s[i]!='$') ans+=s[i];
        }
        return ans;
    }
};