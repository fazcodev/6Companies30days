#define ll long long
class Solution {
public:
    ll dfs(int curr, int prev, vector<int>v[], vector<int>&vis, int t, vector<int>&amt, int dp[]){
        ll val = 0;
        
        if(dp[curr] != -1)return dp[curr];
        if(t == vis[curr]){
            val+=amt[curr]/2;
        }
        else if(t < vis[curr])val+=amt[curr];
        if(prev != -1 && v[curr].size()  == 1)return val;
        ll temp = INT_MIN;
        for(auto &i: v[curr]){
            if(i != prev)temp = max(temp, dfs(i, curr, v, vis, t+1, amt, dp));
        }
        return dp[curr] = val+temp;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int dp[100001];
        memset(dp, -1, sizeof(dp));
        vector<int>v[100005];
        for(auto &i: edges){
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
        queue<int>q;
        q.push(0);
        vector<int>vis(100001, 0);
        int par[100001];
        memset(par, -1, sizeof(par));
        vis[0] = 1;
        while(!q.empty()){
            int sq = q.size();
            bool f = 0;
            for(int i= 0; i<sq; i++){
                int curr = q.front();
                if(curr == bob){
                    f = 1;
                    break;
                }
                q.pop();
                for(auto &j: v[curr]){
                    if(!vis[j]){
                        vis[j] = 1;
                        par[j] = curr;
                        q.push(j);
                    }
                }
            }
            if(f)break;
            
        }
        vis.clear();
        vis.resize(100001, INT_MAX);
        int time = 0;
        while(bob != 0){
            vis[bob] = time;
            bob = par[bob];
            time++;
        }
        vis[0] = time;
        ll ans = dfs(0, -1, v, vis, 0, amount, dp);
        return ans;
    }
  
};
