class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        set<int> pq;
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                if(i==0 || j==0 || i==r-1 || j==c-1){
                    pq.insert(grid[i][j]);
                    if(pq.size()>3){
                        pq.erase(pq.begin());
                    }
                    continue;
                }
                pq.insert(grid[i][j]);
                
                if(pq.size()>3){
                    pq.erase(pq.begin());
                }
                
                for(int k=1;k<min(r,c)/2 + 1;++k){
                    
                    if(i+k < r && i-k >=0 && j+k<c && j-k>=0){
                        int temp=0;
                        for(int a=k,b=0;a>=0 && b<=k;a--,b++){
                            temp+=grid[i+a][j+b];
                        }
                        for(int a=k,b=0;a>=0 && b<=k;a--,b++){
                            temp+=grid[i-a][j+b];
                        }
                        for(int a=k,b=0;a>=0 && b<=k;a--,b++){
                            temp+=grid[i+a][j-b];
                        }
                        for(int a=k,b=0;a>=0 && b<=k;a--,b++){
                            temp+=grid[i-a][j-b];
                        }
                        temp -= (grid[i+k][j]+grid[i][j+k]+grid[i-k][j]+grid[i][j-k]);
                        pq.insert(temp);
                        if(pq.size()>3){
                            pq.erase(pq.begin());
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
        vector<int> ans;
        int i=3;
        while(i-- && !pq.empty()){
            ans.push_back(*pq.begin());
            pq.erase(pq.begin());
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
