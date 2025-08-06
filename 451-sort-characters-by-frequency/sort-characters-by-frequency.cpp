class Solution {
public:
struct Compare {
    bool operator()(pair<int, char>& a, pair<int, char>& b) {
        if (a.first == b.first)
            return a.second > b.second; // lexicographically smaller comes first if freq same
        return a.first < b.first; // higher frequency comes first
    }
};
    string frequencySort(string s) {

        unordered_map<char, int> freq;
        for(char c: s){ // step1: count freq of each character
        freq[c]++;
        }
        // step2: define max heap(priority_ queue)
        priority_queue<pair<int, char>, vector<pair<int, char>>, Compare> maxHeap;
        // step3: push each character & its frequency into the heap
        for(auto& entry:freq){
            maxHeap.push({entry.second, entry.first});// {frequency, character}
        }
        //step4: Build result string
        string result = "";
    while (!maxHeap.empty()) {
        auto top = maxHeap.top(); maxHeap.pop();
        result += string(top.first, top.second);
    }

    return result;
    }
};