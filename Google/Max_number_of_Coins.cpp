class Solution {
public:
    int maxCoins(vector<int>& piles) {
        multiset<int>s(piles.begin(), piles.end());
        int ans = 0;
        while(!s.empty()){
            s.erase(--s.end());
            ans+=*(--s.end());
            s.erase(--s.end());
            s.erase(s.begin());
        }
        return ans;
    }
};
