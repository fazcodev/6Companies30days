class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dun) {
        int n = dun.size(), m = dun[0].size();
        vector<vector<int>>dp(n, vector<int>(m, 0));
        dp[n-1][m-1] = max(0, -1*dun[n-1][m-1]);
        for(int i = m-2; i>=0; i--)dp[n-1][i] = max({0, dp[n-1][i+1]-dun[n-1][i], -1*dun[n-1][i]});
        for(int i = n-2; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                dp[i][j] = max({0, dp[i+1][j]-dun[i][j], -1*dun[i][j]});
                if(j+1 < m){
                    int val = max({0, dp[i][j+1]-dun[i][j], -1*dun[i][j]});
                    dp[i][j] = min(dp[i][j], val);
                }
            }
        }
        return dp[0][0]+1;
    }
};
