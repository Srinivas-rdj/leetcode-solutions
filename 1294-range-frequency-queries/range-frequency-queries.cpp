class RangeFreqQuery {
public:
    int maxi=1e4+1;
    vector<vector<int>> v;
    RangeFreqQuery(vector<int>& arr) {
        v.resize(maxi);
        for(int i=0;i<arr.size();i++){
            v[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        int x=upper_bound(v[value].begin(),v[value].end(),right)-v[value].begin();
        int y=lower_bound(v[value].begin(),v[value].end(),left)-v[value].begin();
        return x-y;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */