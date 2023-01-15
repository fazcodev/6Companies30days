#define ff first
#define ss second
#define pb push_back
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        vector<int>ans;
        int n = nums.size(), sn = nums[0].size();
        vector<pair<string, int>>v[sn+1];
        for(int i= 0; i<n; i++){
            string temp = "";
            temp+=nums[i].back();
            v[1].pb({temp, i});
        }
        sort(v[1].begin(), v[1].end());
        for(int i= 2; i<=sn; i++){
            for(int j = 0; j<n; j++){
                int idx = v[i-1][j].ss;
                string temp = nums[idx][sn-i]+v[i-1][j].ff;
                v[i].pb({temp, idx});
            }
            sort(v[i].begin(), v[i].end());
        }
        
        for(auto &i: q){
            int k = i[0], cnt = i[1];
            k--;
            ans.pb(v[cnt][k].ss);
        }
        return ans;
    }
};
