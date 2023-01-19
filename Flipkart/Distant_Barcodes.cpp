#define ff first
#define ss second
#define pii pair<int, int>
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& b) {
        map<int, int>mp;
        int n = b.size();
        for(int i= 0; i<n; i++)mp[b[i]]++;
        vector<int>ans(n, 0);
        vector<pii>freq;
        for(auto &i: mp)freq.push_back({i.ss, i.ff});
        sort(freq.begin(), freq.end(), greater<pii>());
        int j = 0;
        for(int i= 0; i<n; i+=2){
            if(!freq[j].ff)j++;
            freq[j].ff--;
            ans[i] = freq[j].ss;
        }
        for(int i = 1; i<n; i+=2){
            if(!freq[j].ff)j++;
            freq[j].ff--;
            ans[i] = freq[j].ss;
        }
        return ans;
    }
};
