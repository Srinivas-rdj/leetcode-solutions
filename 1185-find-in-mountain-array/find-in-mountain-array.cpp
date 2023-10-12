/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int t, MountainArray &v) {
        vector<int> vec(v.length(),-1);
        int l=1,r=vec.size()-2,mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(vec[mid]==-1){
                vec[mid]=v.get(mid);
            }
            if(vec[mid-1]==-1) vec[mid-1]=v.get(mid-1);
            if(vec[mid+1]==-1) vec[mid+1]=v.get(mid+1);
            if(vec[mid]>vec[mid-1]&&vec[mid]>vec[mid+1]) break;
            if(vec[mid]>vec[mid-1]) l=mid+1;
            else r=mid-1; 
        }
        l=0,r=mid;
        while(l<=r){
           int  mid1=l+(r-l)/2;
            if(vec[mid1]==-1){
                vec[mid1]=v.get(mid1);
            }
            if(vec[mid1]==t) return mid1;
            if(vec[mid1]>t) r=mid1-1;
            else l=mid1+1;
        }
        l=mid+1,r=vec.size()-1;
        while(l<=r){
            int mid1=l+(r-l)/2;
            if(vec[mid1]==-1){
                vec[mid1]=v.get(mid1);
            }
            if(vec[mid1]==t) return mid1;
            if(vec[mid1]>t) l=mid1+1;
            else r=mid1-1;
        }
        return -1;
    }
};