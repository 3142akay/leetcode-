class Solution {
public:
    int minMaxDifference(int num) {
        std::string numStr = std::to_string(num);
        std::unordered_set<char> uniqueDigits(numStr.begin(), numStr.end());
        
        int maxNum = num;
        int minNum = num;

        // Calculate the maximum number
        for (char d : uniqueDigits) {
            // Replace digit d with '9' to maximize
            std::string maxStr = numStr;
            std::replace(maxStr.begin(), maxStr.end(), d, '9');
            maxNum = std::max(maxNum, std::stoi(maxStr));
        }
        
        // Calculate the minimum number
        for (char d : uniqueDigits) {
            // Replace digit d with '0' to minimize (but not if d is '0')
            if (d != '0') {
                std::string minStr = numStr;
                std::replace(minStr.begin(), minStr.end(), d, '0');
                minNum = std::min(minNum, std::stoi(minStr));
            }
        }
        
        return maxNum - minNum;
        
    }
};