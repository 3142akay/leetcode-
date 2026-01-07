class Solution {
public:
    int findGCD(vector<int>& nums) {
       int minvalue = *min_element(nums.begin(), nums.end());
       int maxvalue = *max_element(nums.begin(), nums.end());
       return gcd(minvalue, maxvalue);
    }
};