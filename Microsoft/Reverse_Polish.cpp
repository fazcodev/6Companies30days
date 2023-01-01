class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>s;
        int n = tokens.size();
        for(int i =0; i<n; i++)
        {
            if(s.empty()|| (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "/" && tokens[i] != "*" ))s.push(tokens[i]);
            else{
                int ff= stoi(s.top());
                s.pop(); int ss = stoi(s.top());
                s.pop();
                if(tokens[i] == "+")ss+=ff;
                else if(tokens[i] == "*")ss*=ff;
                else if(tokens[i] == "-")ss-=ff;
                else ss/=ff;
                s.push(to_string(ss));
            }
        }
        int ans = stoi(s.top());
        return ans;
    }
};
