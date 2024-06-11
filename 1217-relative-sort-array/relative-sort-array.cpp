class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> v;
        vector<int> mp(1001,0);
        for(int i:arr1) mp[i]++;
        for(int i=0;i<arr2.size();i++){
            while(mp[arr2[i]]--){
                v.push_back(arr2[i]);
            }
            // mp.erase(arr2[i]);
        }
        for(int i=0;i<1001;i++){
            while(mp[i]>0){
                v.push_back(i);
                mp[i]--;
            }
        }
        return v;
    }
};