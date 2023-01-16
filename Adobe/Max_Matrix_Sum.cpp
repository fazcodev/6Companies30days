#define ll long long
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        ll mi = INT_MAX, sum = 0, cnt = 0, n = matrix.size();
        bool z = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(matrix[i][j] == 0)z = 1;
                sum+=(ll)abs(matrix[i][j]);
                mi = min(mi, (ll)abs(matrix[i][j]));
                if(matrix[i][j] < 0)cnt++;
            }
        }
        if(z)return sum;
        if(cnt%2)return sum-2ll*mi;
        return sum;
    }
};
