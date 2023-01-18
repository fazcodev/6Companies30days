#define loop(i, a, b) for(int i = a; i<=b; i++)
#define pb push_back
#define MAXN 1000000
vector<int> prime;
int lp[MAXN+1];
void sieve(){loop(i, 2, MAXN){if(lp[i] == 0){lp[i] = i;prime.pb(i);}for(int j = 0; j<(int)prime.size() && prime[j]<=lp[i] && i*prime[j]<=MAXN;++j){lp[i*prime[j]] = prime[j];}}}
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        sieve();
        if(left == right)return {-1, -1};
        sort(prime.begin(), prime.end());
        auto litr= lower_bound(prime.begin(), prime.end(), left);
        auto ritr = lower_bound(prime.begin(), prime.end(), right);
        if(ritr == prime.begin())return {-1, -1};
        if(litr == prime.end() || *litr > right)litr--;
        if(ritr == prime.end() || *ritr > right)ritr--;
        int val1 = -1, val2 = -1, diff = INT_MAX;
        for(auto itr = litr; itr<ritr; itr++){
            if(*itr >= left && *(itr+1)>=left && diff > *(itr+1)-(*itr)){
                val1 = *itr;
                val2 = *(itr+1);
                diff = val2-val1;
            }
        }
        return {val1, val2};
    }
};
