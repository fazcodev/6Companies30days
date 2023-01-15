class Solution {
public:
    int ans = INT_MAX;
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        int n = bank.size();
        set<int>s;
        recur(startGene, endGene, bank, n, s, 0);
        if(ans == INT_MAX)return -1;
        return ans;
    }
    void recur(string &st, string &e, vector<string>&v, int n, set<int>&s, int cnt){
        if(st == e){
            ans = min(cnt, ans);
            return;
        }
        for(int i= 0; i<n; i++){
            if(!s.count(i)){
                int curr = 0;
                for(int j = 0; j<8; j++)if(st[j] != v[i][j])curr++;
                if(curr == 1){
                    s.insert(i);
                    recur(v[i], e, v, n, s, cnt+1);
                    s.erase(i);
                }
            }
        }
    }
};
