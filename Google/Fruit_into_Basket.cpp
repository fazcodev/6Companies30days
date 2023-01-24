class Solution {
public:
    int totalFruit(vector<int>& f) {
        int b1 = 0, b2 = 0, ans = 0, t1 = -1, t2 = -1, n = f.size(), val = 0;
        int prev = -1;
        for(int i= 0; i<n; i++){
            if(t1 == -1 || t1 == f[i]){
                t1 = f[i];
                if(prev != t1){
                    val+=b2;
                    b2 = 0;
                    prev = t1;
                }
                b1++;
            }
            else if(t2 == -1 || t2 == f[i]){
                t2 = f[i];
                if(prev != t2){
                    val+=b1;
                    b1 = 0;
                    prev = t2;
                }
                b2++;
            }
            else{
                ans = max(ans, val+b1+b2);
                val = 0;
                if(prev == t2){
                    val+=b2;
                    t1 = t2; t2 = f[i];
                    b1 = 0;b2 = 1;
                }
                else{
                    val+=b1;
                    b1 = 0;
                    t2 = f[i];
                    b2 = 1;
                }
                prev = f[i];
            }
        }
        ans = max(ans, val+b1+b2);
        return ans;
    }
};
