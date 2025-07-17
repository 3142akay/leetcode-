class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char, int> lastIndex;
        int left = 0, maxLen = 0;
        
        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];
            
            if (lastIndex.find(currentChar) != lastIndex.end() && lastIndex[currentChar] >= left) {
                left = lastIndex[currentChar] + 1;
            }
            
            lastIndex[currentChar] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};