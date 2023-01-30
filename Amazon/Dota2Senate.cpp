class Solution {
public:
    string predictPartyVictory(string s) {
        int n = s.size(), d = 0, r = 0, cntd = 0, cntr = 0;
        for(auto &i: s){
            if(i == 'D')cntd++;
            else cntr++;
        }
        while(cntr && cntd){
            for(int i= 0; i<n; i++){
                if(s[i] == 'R'){
                    if(!r){
                        d++;
                    }
                    else{
                        s[i]= '#';
                        r--; cntr--;
                    }
                }
                else if(s[i] == 'D'){
                    if(!d){
                        r++;
                    }
                    else{
                        s[i] = '#'; d--; cntd--;
                    }
                }
                if(cntr == 0 || cntd == 0)break;
            }
        }
        if(cntd)return "Dire";
        else return "Radiant";
        
        
    }
};
