class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for(int i =0; i<strs.size(); i++){
            string str = strs[i];
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }
        vector<vector<string>> result;
        for(auto& pair : mp){
            result.push_back(pair.second);
        }
        return result;
    }
};