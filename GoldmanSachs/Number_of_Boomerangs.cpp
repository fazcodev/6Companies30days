#define ss second
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0, n = points.size();
        for(int i= 0; i<n; i++){
            // int val = 0;
            unordered_map<int, int>mp;
            for(int j = 0; j<n; j++){
                if(i == j)continue;
                int t = pow(points[i][0]-points[j][0], 2)+pow(points[i][1]-points[j][1], 2);
                mp[t]++;
            }
            for(auto &i: mp)ans+=(i.ss)*(i.ss-1);
        }
        return ans;
    }
};
