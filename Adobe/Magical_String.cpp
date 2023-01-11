class Solution {
public:
    string s;
    int magicalString(int n) {
        s = "12211";
        int ans = 0;
        if(n <= 5){
            for(int i= 0; i<min(n, 5); i++)if(s[i] == '1')ans++;
            return ans;
        } 
        int i= 3, curr = 5;
        while(curr < n){
            if(s[i] == '1'){
                if(s.back() == '1')s+='2';
                else{
                    s+='1';
                }
                curr++;
            }
            else{
                if(s.back() == '1')s+="22";
                else{
                    s+="11";
                }
                curr+=2;
            } 
            i++;

        }
        for(int i= 0;i<n; i++)if(s[i] == '1')ans++;
        return ans;
    }
};
