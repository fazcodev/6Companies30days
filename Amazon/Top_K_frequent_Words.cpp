#define pb push_back
#define ff first
#define ss second
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n = words.size();
        map<string, int>mp;
        for(int i= 0; i<n; i++){
            mp[words[i]]++;
        }
        vector<pair<int, string>>v;
        for(auto &i: mp){
            v.pb({i.ss, i.ff});
        }
        auto comp = [&](pair<int, string>a, pair<int, string>b){
            if(a.ff > b.ff)return 1;
            if(a.ff == b.ff){
                if(a.ss < b.ss)return 1;
                return 0;
            }
            return 0;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(comp)>pq(comp);
        int sz = 0;
        for(auto &i: v){
            if(sz < k){
                pq.push(i);
                sz++;
            }
            else{
                if(pq.top().ff < i.ff){
                    pq.pop();
                    pq.push(i);
                }
                else if(pq.top().ff == i.ff && pq.top().ss > i.ss){
                    pq.pop();
                    pq.push(i);
                }
            }
            
        }
        vector<string>ans;
        while(!pq.empty()){
            ans.pb(pq.top().ss);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
