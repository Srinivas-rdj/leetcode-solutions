class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> v;
        int j=1;
        for(int i=0;i<target.size();i++){
            while(j!=target[i]){
                j++;
                v.push_back("Push");
                v.push_back("Pop");
            }
            v.push_back("Push");
            j++;
        }
        return v;
    }
};