#define ff first
#define ss second
#define pii pair<int, int>
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        multiset<pii>s;
        s.insert({nums[0]+1, 1});   
        int n = nums.size();
        for(int i= 1; i<n; i++){
            auto itr = s.lower_bound({nums[i], 0});
            if(itr == s.end() || itr->ff != nums[i])s.insert({nums[i]+1, 1});
            else{
                int val = itr->ss;
                s.erase(itr);
                s.insert({nums[i]+1, val+1});
            }
        }
        for(auto &i: s)if(i.ss < 3)return 0;
        return 1;
    }
};
