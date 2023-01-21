int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};
class Solution {
public:
    int ans = 0, curr = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0;j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    curr = 0;
                    dfs(grid, vis, n, m, i, j);
                    ans = max(curr, ans);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>&grid, vector<vector<int>>&vis, int n, int m, int x, int y){
        vis[x][y] = 1;
        curr++;
        for(int i= 0; i<4; i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx < n && ny< m && nx>=0 && ny>=0 && vis[nx][ny] == 0 && grid[nx][ny] == 1)dfs(grid, vis, n, m, nx,ny);
        }
        
    }
};
