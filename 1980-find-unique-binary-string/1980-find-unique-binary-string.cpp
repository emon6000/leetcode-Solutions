class Solution {
public:
    void generatebinstring(int n, string current, vector<string>& result) {
        if (current.size() == n) {
            result.push_back(current);
            return;
        }
        generatebinstring(n, current + "0", result);
        generatebinstring(n, current + "1", result);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int l = nums[0].size();
        vector<string> result;
        generatebinstring(l, "", result);
        for (const string& candidate : result) {
            bool found = false;
            for (const string& s : nums) {
                if (s == candidate) {
                    found = true;
                    break;
                }
            }
            if (!found)
                return candidate;
        }
        return "";
    }
};