#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
#define mod 1000000007ll
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<ll>pref(n+1, 0);
        for(int i= 0; i<n; i++){
            pref[i+1] = pref[i]+(ll)nums[i];
        }
        vector<pii>nexts(n, {-1, -1});
        stack<int>s;
        for(int i= 0; i<n; i++){
            if(s.empty())s.push(i);
            else{
                while(!s.empty() && nums[i] < nums[s.top()]){
                    int idx = s.top();
                    nexts[idx].ff = i;
                    s.pop();
                    if(!s.empty())nexts[idx].ss = s.top();
                    
                }
                s.push(i);
            }
        }
        while(!s.empty()){
            int idx = s.top();
            s.pop();
            if(!s.empty())nexts[idx].ss = s.top();
        }
        ll ans = 0;
        for(int i= 0; i<n; i++){
            int r = n, l = -1;
            if(nexts[i].ff != -1)r = nexts[i].ff;
            if(nexts[i].ss != -1)l = nexts[i].ss;
            ans = max(ans, (ll)nums[i]*(pref[r]-pref[l+1]));
        }
        return ans%mod;
    }
};
