class Solution {
public:
    int char2num(char a) {
        switch (a) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.length(); i++) {
            if (i + 1 < s.length() && char2num(s[i]) < char2num(s[i + 1])) {
                result -= char2num(s[i]);
            } else {
                result += char2num(s[i]);
            }
        }
        return result;
        // unordered_map<char, int> roman = {
        //     {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        //     {'C', 100}, {'D', 500}, {'M', 1000}
        // };
        // int total = 0;
        // int n = s.length();
        // for (int i = 0; i < n; i++) {
        //     if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
        //         total -= roman[s[i]];
        //     } else {
        //         total += roman[s[i]];
        //     }
        // }

        // return total;
    }
};