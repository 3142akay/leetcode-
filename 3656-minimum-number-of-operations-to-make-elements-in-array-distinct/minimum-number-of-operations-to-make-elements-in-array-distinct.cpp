class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int operations = 0;
        while (true) {
            if (hasDistinctElements(nums)) {
                return operations;
            }
            if (nums.size() >= 3) {
                nums.erase(nums.begin(), nums.begin() + 3);
            } else {
                nums.clear();
            }
            operations++;
            if (nums.empty()) {
                return operations;
            }
        }
    }

private:
    bool hasDistinctElements(const vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) {
                return false;
            }
            seen.insert(num);
        }
        return true;
    }
};