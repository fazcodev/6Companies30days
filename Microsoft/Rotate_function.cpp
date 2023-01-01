class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size(), total = 0, ans = 0, curr = 0;
        for(int i= 0; i<n; i++){
            curr+=i*nums[i];
            total+=nums[i];
        }
        ans = curr;
        for(int i = n-1; i>=1; i--){
            curr+=(total-nums[i]-(n-1)*nums[i]);
            ans = max(ans, curr);
        }
        return ans;
    }
};
