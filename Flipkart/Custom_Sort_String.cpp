class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int>mp;
        for(auto &i: s)mp[i]++;
        string ans = "";
        for(auto &i : order){
            while(mp[i]){
                ans+=i;
                mp[i]--;
            }
        }
        
        for(auto &i: mp){
            while(i.second != 0){
                ans+=i.first;
                i.second--;
            }
        }
        return ans;
    }
};
