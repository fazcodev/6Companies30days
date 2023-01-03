#define ll long long
#define pll pair<ll, ll>
#define pii pair<int,int>
#define ff first
#define ss second
#define mod 1000000007
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pll>dist(n, {1e17, 0});
        vector<pll>g[200];
        for(auto &i: roads){
            g[i[0]].push_back({i[1], (ll)i[2]});
            g[i[1]].push_back({i[0], (ll)i[2]});
        }
        dist[0] = {0, 1};
        auto comp = [&](pll a, pll b){
            return a.ss > b.ss;
        };
       
        priority_queue<pll, vector<pll>, decltype(comp)>pq(comp);
         pq.push({0, 0});
        while(!pq.empty()){
            pll node = pq.top();
            pq.pop();
            for(auto &i: g[node.ff]){
                if(dist[i.ff].ff == node.ss+i.ss){
                    dist[i.ff].ss = (dist[i.ff].ss+dist[node.ff].ss)%mod;
                }
                else if(dist[i.ff].ff > node.ss+i.ss){
                    dist[i.ff].ff = node.ss+i.ss;
                    dist[i.ff].ss = dist[node.ff].ss;
                    pq.push({i.ff, dist[i.ff].ff});
                }
            }
        }
        return dist[n-1].ss;
    }
};
