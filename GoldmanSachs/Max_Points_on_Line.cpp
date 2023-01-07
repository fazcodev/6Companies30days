class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        for(int i=0;i<n;i++){
            map<pair<int,int>,int> slope;
            for(int j=i+1;j<n;j++){
                int dy=points[i][1]-points[j][1];
                int dx=points[i][0]-points[j][0];
                int g= __gcd(dy,dx);
                dy/=g;
                dx/=g;
                slope[{dy,dx}]++;

                
                
            }
            for(auto it:slope){
                ans=max(ans,it.second+1);

            }
        }
        return max(ans, 1);
    }
};
