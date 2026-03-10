class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>s;
        for(int i=0;i<nums.size();i++){
            s.push_back(to_string(nums[i]));
        }
        sort(s.begin(), s.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });
        if (s[0] == "0") {
            return "0";
        }

        string result = "";
        for (const string &ss : s) {
            result += ss;
        }

        return result;
    }
};