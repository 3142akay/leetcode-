class Solution {
public:
    int maximum69Number (int num) {
        string s=to_string(num);
        for(auto &chr:s){
            if(chr=='6'){
                chr='9';
                break;
            }
        }
        return stoi(s);
    }
};