class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxDiff = -1; // Initialize the maximum difference to -1
        int minValue = nums[0]; // Start with the first element as the minimum

        for (int j = 1; j < nums.size(); ++j) {
            // Check if the current number is greater than the minimum value found so far
            if (nums[j] > minValue) {
                maxDiff = max(maxDiff, nums[j] - minValue); // Update maxDiff if a larger difference is found
            }
            // Update the minimum value if the current number is smaller
            minValue = min(minValue, nums[j]);
        }

        return maxDiff; // Return the maximum difference found, or -1 if none exists
        
    }
};