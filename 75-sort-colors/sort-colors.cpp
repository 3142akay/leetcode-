class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;          // Pointer for 0
    int mid = 0;          // Pointer for current element
    int high = nums.size() - 1;  // Pointer for 2

    while (mid <= high) {
        switch (nums[mid]) {
            case 0:
                swap(nums[low++], nums[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(nums[mid], nums[high--]);
                break;
        }
    }
}


        
    };
