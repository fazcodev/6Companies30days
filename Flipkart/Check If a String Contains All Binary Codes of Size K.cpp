class Solution {
public:
    int fastexpo(int a, int b){
        if(b == 0)return 1;
        int val = fastexpo(a, b/2);
        if(b%2 == 0){
            
            return val*val;
        }
        else return val*val*a;
    }
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        unordered_set<string>st;
        for(int i = 0; i<=n-k; i++){
            st.insert(s.substr(i, k));
        }
        int cnt = st.size();
        return cnt == fastexpo(2, k);
    }
};
