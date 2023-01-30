class Solution {
public:
    int dp[1001][1001];
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(), ans = 0;
        memset(dp, 0, sizeof(dp));
        if(nums1[0] == nums2[0])dp[0][0] = 1;
        for(int i= 0; i<n; i++){
            if(nums1[i] == nums2[0])dp[0][i] = 1;
        }

        for(int i= 1; i<m; i++){
            for(int j =0; j<n; j++){
                if(j == 0 && nums1[j] == nums2[i])dp[i][j] = 1;
                else if(nums1[j] == nums2[i])dp[i][j] = dp[i-1][j-1]+1;
                ans = max(ans, dp[i][j]);

            }
        }
        return ans;
    }
};
