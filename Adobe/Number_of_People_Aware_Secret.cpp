#define mod 1000000007
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int>dp(n, 0);
        dp[0] = 1;
        for(int i= 0; i<n; i++){
            for(int j = i+delay; j<i+forget && j <n; j++){
                dp[j] = (dp[j]+dp[i])%mod;
            }
        }
        int sum = 0;
        for(int i = n-1; i>n-1-forget && i>=0; i--){
            sum = (sum+dp[i])%mod;
        }
        return sum;
    }
};
