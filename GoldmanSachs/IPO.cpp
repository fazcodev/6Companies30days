#define pii pair<int,int>
#define ff first
#define ss second
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) {
        int n = profit.size();
        vector<pii>v(n);
        for(int i= 0; i<n; i++){
            v[i] = {capital[i], profit[i]};
        }
        sort(v.begin(), v.end());
        priority_queue<int>pq;
        int i = 0, cnt = 0, curr = w;
        while(i<n && cnt < k){
            if(curr >= v[i].ff){
                pq.push(v[i].ss);
                i++;
            }
            else{
                if(pq.empty())break;
                curr+=pq.top();
                cnt++;
                pq.pop();
            }
        }
        while(cnt < k && !pq.empty()){
            curr+=pq.top();
            cnt++;
            pq.pop();
        }
        return curr;
    }
};
