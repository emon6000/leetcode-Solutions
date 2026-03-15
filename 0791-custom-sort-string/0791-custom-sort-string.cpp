class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for (char c : s) {
            mp[c]++;
        }

        string result = "";

        for (char c : order) {
            if (mp.count(c)) {
                result.append(mp[c], c);
                mp[c] = 0;
            }
        }

        for (auto const& [ch, count] : mp) {
            if (count > 0) {
                result.append(count, ch);
            }
        }

        return result;
    }
};