#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update >; // find_by_order, order_of_key

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n= nums1.size();
        ll cnt = 0;
        pbds<int>s;
        int sz = 0;
        for(int i = n-1; i>=0; i--){
            int val = nums1[i]-nums2[i];
            cnt+=sz-s.order_of_key(val);
            s.insert(val+diff);
            sz++;
        }
        return cnt;
    }
};
