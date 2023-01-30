#define ff first
#define ss second
#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string, pll>mp;
        ll n = views.size(), mval = 0;
        vector<vector<string>>ans;
        for(int i= 0; i<n; i++){
            if(mp.find(creators[i]) == mp.end()){
                mp[creators[i]].ff=views[i];
                mp[creators[i]].ss = i;
            }
            else{
                mp[creators[i]].ff+=views[i];
                int idx = mp[creators[i]].ss;
                if(views[idx] < views[i]){
                    mp[creators[i]].ss = i;
                }
                else if(views[idx] == views[i] && ids[idx] > ids[i]){
                    mp[creators[i]].ss = i;
                }
            }
            mval = max(mval, mp[creators[i]].ff);
        }
        for(auto &i: mp){
            if(i.ss.ff == mval){
                ans.push_back({i.ff, ids[i.ss.ss]});
            }
        }
        return ans;
        
    }
};
