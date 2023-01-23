int pow2[16]{};
class Solution {
public:
    int ans = 0;
    int maximumGood(vector<vector<int>>& st) {
        int n = st.size();
        pow2[0] = 1;
        for(int i = 1; i<16; i++)pow2[i] = pow2[i-1]*2;
        for(int p = 0; p<pow2[n]; p++){
            int b = 0, cnt = 0;
            vector<int>v(n, 2);
            while(b < n){
                if((p&(1<<b)) && (v[b]==2 || v[b] == 1)){
                    cnt++;
                    v[b] = 1;
                    bool f= 1;
                    for(int i = 0; i<n; i++){
                        if(st[b][i] == 2)continue;
                        if(v[i] == 2 || v[i] == st[b][i]){
                            v[i] = st[b][i];
                        }
                        else{
                            f = 0;break;
                        }
                    }
                    if(!f)break;
                }
                else if(!(p&(1<<b)) && (v[b] == 2 || v[b] == 0))v[b]=0;
                else break;
                b++;
            }
            if(b == n)ans = max(ans, cnt);
        }
        return ans;
       
    }
    // void recur(vector<int>v, vector<vector<int>>&st,int i,int n,int cnt, vector<int>&val){
    //     if(i == n){
    //         ans = max(ans, cnt);
    //         return;
    //     }
    //     vector<int>temp = v;
    //     if(v[i] == 2 || v[i] == 1){
    //         v[i]= 1;
    //         bool f = 1;
    //         for(int j = 0; j<n; j++){
    //             if(st[i][j]!=2){
    //                 if(v[j] == 2 || v[j] == st[i][j])v[j] = st[i][j];
    //                 else{
    //                     f = 0;break;
    //                 }
    //             }
    //         }
    //         if(f)recur(v, st, i+1, n, cnt+1, val);
    //         v = temp;
    //     }
    //     if(v[i] == 2 || v[i] == 0){
            
    //         for(int p= 0; p<=pow2[val[i]]-1; p++){
    //             int b = 0, j = 0;
    //             v = temp;
    //             v[i] = 0;
    //             while(b < val[i]){
    //                 if(st[i][j] != 2){
    //                     if((p&(1<<b))){
    //                         if(v[j]==2||v[j]==st[i][j])v[j]=st[i][j];
    //                         else break;
    //                     }
    //                     else{
    //                         if(v[j]==2||v[j]!=st[i][j])v[j]=!st[i][j];
    //                         else break;
    //                     }
    //                     b++;
    //                 }
    //                 j++;
    //             }
    //             if(b ==val[i]){
    //                 recur(v, st, i+1, n, cnt, val);
    //             } 
    //         }
    //     }
    // }
};
