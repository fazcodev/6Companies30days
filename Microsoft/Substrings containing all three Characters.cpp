class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0, n = s.size(), a[3]{}, l = 0, r = 0;
        while(r < n){
            a[s[r]-'a']++;
            // int ca = a[0], cb = a[1], cc = a[2];
            if(a[0]>=1 && a[1]>=1 && a[2]>=1){
                while(a[0]>=1 && a[1]>=1 && a[2]>=1){
                    if(--a[s[l]-'a'] == 0)cnt+=(l+1);
                    l++;
                }
            }
            else{
                while(l>0 && (a[0] == 0 || a[1] == 0 || a[2] == 0)){
                    l--;
                    a[s[l]-'a']++;
                }
                if(a[0]>=1 && a[1]>=1 && a[2]>=1)cnt+=(l+1);
            }
            
            r++;
        }
        return cnt;
    }
};
