class Solution {
public:
    // The usual way of solving the problem is recursion which has 2^(K*N) complexity whereas the bitmasking approach has complexity N*(2^N)
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i= 0; i<n; i++)sum+=nums[i];
        if(k == 1)return 1;
        if(k > n)return 0;
        if(sum%k != 0)return 0;
    
        int tar = sum/k;
        vector<int>dp(1<<18, -1);
        dp[0] = 0;
        for(int mask = 0; mask<(1<<n); mask++){
            if(dp[mask] == -1)continue;
            for(int i = 0; i<n; i++){
                if(!(mask&(1<<i)) && dp[mask]+nums[i] <= tar){
                    dp[mask|(1<<i)] = (dp[mask]+nums[i])%tar;
                }
            }
        }
        return dp[(1<<n)-1]==0 ? 1: 0;
    }
};
