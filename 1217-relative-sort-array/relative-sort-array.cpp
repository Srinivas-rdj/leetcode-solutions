class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> v;
        map<int,int> mp;
        for(int i:arr1) mp[i]++;
        for(int i=0;i<arr2.size();i++){
            while(mp[arr2[i]]--){
                v.push_back(arr2[i]);
            }
            mp.erase(arr2[i]);
        }
        for(pair<int,int> p:mp){
            while(p.second--){
                v.push_back(p.first);
            }
        }
        return v;
    }
};