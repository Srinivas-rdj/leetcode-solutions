class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int max1=INT_MIN;
        for(int i=0;i<left.size();i++) max1=max(max1,left[i]-0);
        for(int i:right) max1=max(max1,n-i);
        return max1;
    }
};