class Solution {
public:
    vector<int>temp, v;
    int n;
    Solution(vector<int>& nums) {
        temp = nums;
        v = nums;
        n= nums.size();
    }
    
    vector<int> reset() {
        v = temp;
        return temp;
    }
    
    vector<int> shuffle() {
        for(int i= 0; i<n; i++){
            int idx = rand()%n;
            swap(v[i], v[idx]);
        }
        return v;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
