class Solution {
public:
    bool vis[8]{};
    int ans, m, n;
    int maxCompatibilitySum(vector<vector<int>>& st, vector<vector<int>>& men){
        m = st.size(); n = st[0].size();
        ans = 0;
        vector<int>v(m, -1);
        recur(st, men, 0, v);
        return ans;
    }
    void recur(vector<vector<int>>&st, vector<vector<int>>&men, int i, vector<int>v){
        if(i == m){
            int cnt = 0;
            for(int i= 0; i<m; i++){
                for(int j = 0; j<n; j++){
                    if(st[i][j] == men[v[i]][j])cnt++;
                }
            }
            ans = max(ans, cnt);
        }
        for(int j= 0; j<m; j++){
            if(!vis[j]){
                vis[j]= 1;
                v[i] = j;
                recur(st, men, i+1, v);
                vis[j] = 0;
                v[i] = -1;
            }
        }
    }
};
