
class Solution {
public:
    int trailingZeroes(int n) {
        if(n == 0)return 0;
        int tot2 = 0, tot5 = 0, val =n;
        while(val >= 2){
            tot2+=val/2;
            val/=2;
        }
        val =n;
        while(val >= 5){
            tot5+=val/5;
            val/=5;
        }
        return min(tot2, tot5);
    }
};
