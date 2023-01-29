class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int val = 0;
        for(int i= 0; i<m-2; i++){
            for(int j = 0; j<n-2; j++){
                int curr = grid[j+1][i+1];
                for(int k = 0; k<3; k++){
                    curr+=grid[j][i+k]+grid[j+2][i+k];
                }
                val =max(val, curr);
            }
        }
        return val;
    }
};
