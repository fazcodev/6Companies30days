class Solution {
public:
    int findKthNumber(int n, int k) {
        int ans = 1, tdig = log10(n), curr = 0;
        string num = to_string(n), s = "1";
        while(k > 1){
            bool f = 1, c = 0;
            for(int i= 0; i<=curr; i++){
                if(s[i] != num[i]){
                    f = 0;
                    if(s[i] > num[i])c = 1;
                    break;

                }
            }
            int total = 0, dig = tdig;
            if(c)dig--;
            for(int i = curr+1; i<dig; i++){
                total+=pow(10, i-curr);
            }
            if(f && s[curr] == num[curr] && curr != dig){
                int extra[12]{};
                extra[dig] = num[dig]-'0'+1;
                for(int i= dig-1; i>=curr+1; i--){
                    extra[i] = (num[i]-'0')*pow(10, dig-i)+extra[i+1];
                }
                total+=extra[curr+1];

            }
            else if(curr != dig){
                total+=pow(10, dig-curr);
            }
            if(total+1 >=k){
                if(k != 1){
                    s+='0';
                    ans = stoi(s);
                    k--;
                    curr++;
                }
                else break;
                
            }
            else{
                k--;
                k-=total;
                ans++;
                s = to_string(ans);
            }
        }
        return ans;
    }
};
