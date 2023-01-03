#define ff first
#define ss second
#define pii pair<int, int>
class Solution {
public:
   
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<pii>dp(n, {0, 0});
        int idx = -1, ma = 0;
        for(int i= 0; i<n; i++){
            dp[i] = {i, 1};
            for(int j = i-1; j>=0; j--){
                if(nums[i]%nums[j] == 0 && dp[j].ss+1 > dp[i].ss){
                    dp[i].ss = dp[j].ss+1;
                    dp[i].ff = j;
                }
            }
            if(ma < dp[i].ss){
                ma = dp[i].ss;
                idx = i;
            }
        }
        vector<int>v;
        while(ma){
            v.push_back(nums[idx]);
            idx = dp[idx].ff;
            ma--;
        }
        return v;
        
    }
};
