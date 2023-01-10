#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update >; // find_by_order, order_of_key

class Solution {
public:
    int idx2[100005];
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        memset(idx2, -1, sizeof(idx2));
        int n = nums1.size();
        for(int i= 0; i<n; i++){
            idx2[nums2[i]] = i;
        }
        ll ans = 0;
        pbds<ll>sl, sr;
        sl.insert(idx2[nums1[0]]);
        for(int i = n-1; i>1; i--)sr.insert(idx2[nums1[i]]);
        for(int i=1; i<n-1; i++){
            ll ls = sl.order_of_key(idx2[nums1[i]]);
            ll gt = sr.size()-sr.order_of_key(idx2[nums1[i]]);
            ans+=(ls*gt);
            sl.insert(idx2[nums1[i]]);
            sr.erase(idx2[nums1[i+1]]);
        }
        return ans;
    }
};
