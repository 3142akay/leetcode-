class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        // If total sum is odd, can't partition
        if (totalSum % 2 != 0) return false;
        
        int target = totalSum / 2;
        int n = nums.size();
        
        // DP array: dp[i] = true if sum i can be formed
        vector<bool> dp(target + 1, false);
        dp[0] = true; // base case: sum 0 can always be formed
        
        for (int num : nums) {
            // Iterate from target down to num to avoid reuse of same element
            for (int i = target; i >= num; --i) {
                if (dp[i - num]) {
                    dp[i] = true;
                }
            }
            // Early exit if target is already found
            if (dp[target]) return true;
        }
        
        return dp[target];
    }
};