#define pii pair<int, int>
#define ff first
#define ss second
class Solution {
public:
    
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pii, int>mp;
        for(auto &i: rectangles){
            mp[{i[0], i[1]}]++;
            mp[{i[2], i[3]}]++;
            mp[{i[0], i[3]}]--;
            mp[{i[2], i[1]}]--;
        }
        int cnt = 0;
        for(auto &i: mp){
            if(i.ss == 1 || i.ss == -1)cnt++;
            else if(i.ss!= 0)return 0;
        }
        return cnt == 4;
        
    }
};
