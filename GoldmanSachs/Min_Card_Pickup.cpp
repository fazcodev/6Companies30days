#define ss second
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        unordered_map<int, vector<int>>mp;
        for(int i= 0; i<n; i++)
        {
            mp[cards[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto &i: mp)
        {
            n = i.ss.size();
            for(int j = 0; j<n-1; j++)
            {
                ans = min(ans, i.ss[j+1]-i.ss[j]+1);
            }
        }
        if(ans == INT_MAX)return -1;
        return ans;
    }
};
