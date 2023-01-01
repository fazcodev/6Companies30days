#define pb push_back
#define ff first
#define ss second
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& val) {
        int g = 0;
        for(auto &i: val)g = gcd(g, i);
        map<int, int>mp;
        for(auto &i: nums)mp[i]++;
        vector<int>fac;
        for(int i= 1; i<=sqrt(g); i++){
            if(g%i ==  0){
                fac.pb(i);
                if(g/i != i)fac.pb(g/i);
            }
        }
        sort(fac.begin(), fac.end());
        int v = -1;
        for(auto &i: fac){
            if(mp.find(i) != mp.end()){
                v = i;break;
            }
        }
        if(v == -1)return -1;
        int cnt = 0;
        for(auto &i: mp){
            if(i.ff != v)cnt+=i.ss;
            else break;
        }
        return cnt;
    }
};
