#define ff first
#define ss second
#define pii pair<int, int>
class Solution {
public:
    vector<pii>g[101];
    vector<int>dist;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(auto &i: times){
            g[i[0]].push_back({i[1], i[2]});
        }
        dist.resize(n+1, INT_MAX);
        dist[k] = 0;
        auto comp = [&](int a, int b){
            return dist[a]> dist[b];
        };
        priority_queue<int, vector<int>, decltype(comp)>pq(comp);
        pq.push(k);
        while(!pq.empty()){
            int node = pq.top();
            pq.pop();
            for(auto i: g[node]){
                if(dist[i.ff] > dist[node]+i.ss){
                    dist[i.ff] = dist[node]+i.ss;
                    pq.push(i.ff);
                }
            }
        }
        int val = 0;
        for(int i= 1; i<=n; i++)val= max(val, dist[i]);
        return val!=INT_MAX?val:-1;
    }
};
