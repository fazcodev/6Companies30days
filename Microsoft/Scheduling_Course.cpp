
class Solution {
public:
    bool vis[2001]{};
    int cnt;
    bool canFinish(int n, vector<vector<int>>& pre) {
        cnt =0;
        vector<int>g[2001];
        int indeg[2001]{};
        for(auto &i: pre){
            g[i[1]].push_back(i[0]);
            indeg[i[0]]++;
        }
        for(int i= 0; i<n; i++){
            if(!vis[i] && indeg[i] == 0){
                topo(i, g, indeg);
            }
        }
        return cnt == n;
    }
    void topo(int src, vector<int>g[], int indeg[]){
        queue<int>q;
        q.push(src);
        vis[src] = 1;
        while(!q.empty()){
            int qs = q.size();
            cnt+=qs;
            for(int i= 0; i<qs; i++){
                int node = q.front();
                q.pop();
                for(auto &j: g[node]){
                    if(--indeg[j] == 0){
                        vis[j] = 1;
                        q.push(j);
                    }
                }
            }
        }
    }
};
