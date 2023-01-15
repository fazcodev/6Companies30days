class Solution {
public:
    map<char,vector<int>>mp;
    bool isSubsequence(string s, string t) {
        int j = 0, n= s.size(), idx = -1;
        for(int j = 0; j<n; j++)
        {
            if(mp.find(s[j]) != mp.end())
            {
                auto itr = upper_bound(mp[s[j]].begin(), mp[s[j]].end(), idx);
                if(itr != mp[s[j]].end())
                {
                    idx = *itr;
                }
                else return 0;
            }
            else return 0;
        }
        return 1;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        int cnt = 0, n = words.size();
        int m = s.size();
        for(int i =0; i<m; i++)
        {
            mp[s[i]].push_back(i);
        }
        for(int i = 0; i<n; i++)
        {
            if(isSubsequence(words[i], s))cnt++;
        }
        return cnt;
    }
};
