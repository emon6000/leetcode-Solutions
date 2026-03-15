class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto& it : freqMap) {
            pq.push({it.second, it.first});
        }
        string result = "";
        while (!pq.empty()) {
            pair<int, char> current = pq.top();
            pq.pop();
            result.append(current.first, current.second);
        }

        return result;
    }
};