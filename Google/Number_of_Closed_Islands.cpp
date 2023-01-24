int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
class Solution {
public:
    bool vis[101][101];
    int closedIsland(vector<vector<int>>& grid) {
        memset(vis, 0, sizeof(vis));
        int cnt = 0, n = grid.size(), m = grid[0].size();
        for(int i=0 ;i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 0){
                    bool f = 1;
                    dfs(i, j, grid, f, n, m);
                    if(f)cnt++;
                }
            }
        }
        return cnt;
    }
    void dfs(int x, int y, vector<vector<int>>&grid, bool&f, int n, int m){
        vis[x][y] = 1;
        for(int d = 0; d<4; d++){
            int nx = dx[d]+x, ny = dy[d]+y;
            if(nx >= 0 && ny >= 0 && nx < n && ny < m){
                if(!vis[nx][ny] && grid[nx][ny] == 0){
                    dfs(nx, ny, grid, f, n, m);
                }
            }
            else f = 0;

        }
    }
};
