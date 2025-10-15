class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // HashMap to store loss count for each player
        unordered_map<int, int> lossCount;
        
        // Track all players who have played at least one match
        for (const auto& match : matches) {
            int winner = match[0];
            int loser = match[1];
            
            // Ensure winner is in the map (if not present, initialize with 0 losses)
            if (lossCount.find(winner) == lossCount.end()) {
                lossCount[winner] = 0;
            }
            
            // Increment loss count for loser
            lossCount[loser]++;
        }
        
        // Separate lists for players with 0 losses and 1 loss
        vector<int> zeroLoss;
        vector<int> oneLoss;
        
        // Iterate through all players in the map
        for (const auto& [player, losses] : lossCount) {
            if (losses == 0) {
                zeroLoss.push_back(player);
            } else if (losses == 1) {
                oneLoss.push_back(player);
            }
        }
        
        // Sort both lists in increasing order
        sort(zeroLoss.begin(), zeroLoss.end());
        sort(oneLoss.begin(), oneLoss.end());
        
        // Return the result
        return {zeroLoss, oneLoss};
    }
};