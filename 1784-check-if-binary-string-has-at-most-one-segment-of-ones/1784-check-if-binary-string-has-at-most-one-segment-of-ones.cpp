class Solution {
public:
    bool checkOnesSegment(string s) {
        vector<string> v;
        string ss = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                ss += "1";
            } else if (s[i] == '0' && ss != "") {
                v.push_back(ss);
                ss = "";
            }
        }
        if (ss != "") {
            v.push_back(ss);
        }
        if (v.size() == 1) {
            return true;
        } else
            return false;
    }
};