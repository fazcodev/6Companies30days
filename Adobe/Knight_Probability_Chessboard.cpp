int dx[8] = {2, 2, 1, 1, -2, -2, -1, -1};
int dy[8] = {1, -1, 2, -2, 1, -1, 2, -2};
class Solution {
public:
    double dp[101][25][25];
    double knightProbability(int n, int k, int row, int column) {
        memset(dp, sizeof(dp), 0);
        for(int i=  0; i<n; i++){
            for(int j = 0; j<n; j++)dp[0][i][j] = 1;
        }
        for(int s = 1; s<=k; s++){
            for(int i=0; i<n; i++){
                for(int j = 0; j<n; j++){
                    double val = 0;
                    for(int d = 0; d<8; d++){
                        int nx = i+dx[d], ny = j+dy[d];
                        if(nx>=0 && ny>=0 && nx <n && ny < n){
                            val+=dp[s-1][nx][ny];
                        } 
                    }
                    val/=8.0;
                    dp[s][i][j] = val;
                }
            }
        }
        return dp[k][row][column];
    }
};
