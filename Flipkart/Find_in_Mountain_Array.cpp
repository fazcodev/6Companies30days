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
    int findInMountainArray(int target, MountainArray &marr) {
        int n = marr.length();
        int l = 0, r = n-1, midx = -1;
        while(l<=r){
            int mid = (l+r)/2;
            int mval = marr.get(mid);
            if(mid-1 < 0){
                l = mid+1; continue;
            }
            if(mid+1 >= n){
                r = mid-1;continue;
            }
            int lval = marr.get(mid-1), rval = marr.get(mid+1);
            if(lval < mval && mval > rval){
                midx = mid;
                break;
            }
            if(lval < mval && rval > mval){
                l = mid+1;
            }
            else r = mid-1;
            
        }
        l = 0; r = midx-1;
        if(marr.get(midx) == target)return midx;
        while(l <= r){
            int mid = (l+r)/2, mval = marr.get(mid);
            if(mval == target)return mid;
            if(mval < target)l = mid+1;
            else r = mid-1;
        }
        l = midx+1; r = n-1;
        while(l <= r){
            int mid = (l+r)/2, mval = marr.get(mid);
            if(mval == target)return mid;
            if(mval < target)r = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};
