class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        // Single digit numbers are always palindromes
        if (x < 10) {
            return true;
        }
        
        // Numbers ending with 0 can't be palindromes (except 0 itself)
        if (x % 10 == 0) {
            return false;
        }
        
        int reversed = 0;
        int original = x;
        
        // Reverse half of the number
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        
        // Compare the two halves
        // For even digits: x == reversed
        // For odd digits: x == reversed / 10
        return x == reversed || x == reversed / 10;
        
    }
};