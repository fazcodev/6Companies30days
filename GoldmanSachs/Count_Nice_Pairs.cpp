#define ll long long
#define mod 1000000007ll
#define ff first
#define ss second
class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        map<int, ll>mp;
        for(auto &i: nums){
            string s= to_string(i);
            reverse(s.begin(), s.end());
            int val = stoi(s);
            mp[i-val]++;
        }
        ll ans = 0;
        for(auto &i: mp){
            ans = (ans+((i.ss*(i.ss-1ll))/2ll)%mod)%mod;
        }
        return ans;
    }
};
