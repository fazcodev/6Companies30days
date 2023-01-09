#define pii pair<int, int>
#define ff first
#define ss second
class Solution {
public:
    
    vector<int> maximumBobPoints(int n, vector<int>& alice) {
        pii dp[12][100005];
        for(int i= 0; i<=n; i++)dp[0][i] = {0, 0};
        for(int i =1; i<12; i++){
            for(int j = 0; j<=n; j++){
                if(j>=alice[i]+1){
                    if(dp[i-1][j-alice[i]-1].ff+i > dp[i-1][j].ff){
                    dp[i][j]={dp[i-1][j-alice[i]-1].ff+i,alice[i]+1};
                    }
                    else dp[i][j] = {dp[i-1][j].ff, 0};
                }
                else dp[i][j] = {dp[i-1][j].ff, 0};
            }
        }
        vector<int>ans(12);
        int cnt = n;
        for(int i=11; i>=0; i--){
            ans[i] = dp[i][cnt].ss;
            cnt-=dp[i][cnt].ss;
        }
        if(cnt)ans[0] = cnt;
        return ans;
    }
};
