class Solution {
public:
    string longestPrefix(string s) {
        int n = s.size(), l= 0, r= 0;
        vector<int>z(n, 0);
        for(int i = 1; i<n; i++)
        {
            if(i<=r)
            {
                z[i] = min(z[i-l], r-i+1);
            }
            while(i+z[i]<n && s[z[i]] == s[i+z[i]])
            {
                z[i]++;
            }
            if(i>r)
            {
                l = i; r = i+z[i]-1;
            }
        }
        int mval = 0, midx = -1;
        for(int i= 1; i<n; i++)
        {
            if(z[i] > mval && z[i] == n-i)
            {
                mval = z[i]; midx = i;
            }
        }
        if(mval == 0)return "";
        return s.substr(midx, mval);
    }
    
};
