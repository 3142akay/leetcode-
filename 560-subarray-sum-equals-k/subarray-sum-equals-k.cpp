class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int result = 0;
        int cumsum = 0;
        mp.insert({0,1});
        for(int i =0; i<nums.size(); i++){
            cumsum += nums[i];
        
        if(mp.find(cumsum-k)!= mp.end()){
            result += mp[cumsum-k];
        }
        mp[cumsum]++;
        
    }
    return result;
    
}
};