#define ll long long
#define mod 1000000007ll
#define pii pair<int, int>
#define ff first
#define ss second
class Solution {
public:
    ll dp[3005][1001];
    int numberOfWays(int startPos, int endPos, int k) {
        startPos+=1000; endPos+=1000;
        memset(dp, -1, sizeof(dp));
        return recur(startPos, endPos, 0, k);
    }
    ll recur(int x, int dest, int i, int k){
        if(i == k){
            if(x == dest)return 1;
            return 0;
        }
        if(dp[x][i] != -1)return dp[x][i];
        return dp[x][i] = (recur(x-1, dest, i+1,k)%mod+recur(x+1, dest, i+1, k)%mod)%mod;

    }
    
};
