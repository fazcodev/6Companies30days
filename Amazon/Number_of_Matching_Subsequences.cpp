#define pb push_back
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& w) {
        int n=  w.size(), sn = s.size(), cnt = 0;
        vector<vector<int>>mp(26);
        for(int i=0; i<sn; i++)mp[s[i]-'a'].pb(i);
        for(int i= 0; i<n; i++){
            int prev = -1;
            bool c= 1;
            for(auto &j: w[i]){
                auto itr = upper_bound(mp[j-'a'].begin(), mp[j-'a'].end(), prev) ;
                if(itr == mp[j-'a'].end()){
                    c = 0;break;
                }
                else prev = *itr;
            }
            cnt+=c;
        }
        return cnt;
    }
};
