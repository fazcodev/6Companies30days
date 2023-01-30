#define ll long long
class Solution {
public:
    bool asteroidsDestroyed(ll mass, vector<int>& ast) {
        sort(ast.begin(), ast.end());
        int n = ast.size();
        for(int i= 0; i<n; i++){
            if(mass < ast[i])return 0;
            mass+=(ll)ast[i];
        }
        return 1;
    }
};
