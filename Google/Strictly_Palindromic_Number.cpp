class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for(int i = 2; i<n-1; i++){
            string val = "";
            int curr = n;
            while(curr >= 1){
                val+=(curr%i)+'0';
                curr/=i;
            }
            if(!pal(val))return 0;
        }
        return 1;
    }
    bool pal(string s){
        int l = 0, hi = s.size()-1;
        while(l<hi){
            if(s[l] != s[hi])return 0;
            l++; hi--;
        }
        return 1;
    }
};
