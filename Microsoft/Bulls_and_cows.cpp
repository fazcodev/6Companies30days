class Solution {
public:
    string getHint(string secret, string guess) {
        int cnt[10]{};
        for(auto &i: secret){
            cnt[i-'0']++;
        }
        int bulls = 0, cows = 0;
        int n = guess.size();
        for(int i= 0; i<n; i++){
            if(guess[i] == secret[i] && cnt[guess[i]-'0']){
                cnt[guess[i]-'0']--;
                bulls++;
            }
        }
        for(int i=0; i<n; i++){
            if(guess[i] != secret[i] && cnt[guess[i]-'0']){
                cnt[guess[i]-'0']--;
                cows++;
            }
        }
        string s = to_string(bulls)+"A"+to_string(cows)+"B";
        return s;

    }
};
