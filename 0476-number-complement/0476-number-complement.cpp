class Solution {
public:
string decToBinary(int n) {

        string bin = "";
        while (n > 0) {
            int bit = n % 2;
            bin.push_back('0' + bit);
            n /= 2;
        }
        reverse(bin.begin(), bin.end());
        return bin;
    }
    int findComplement(int n) {
        if (n == 0)
            return 1;
        int x = __builtin_clz(n);
        int z = 31 - x;
        string s = decToBinary(n);
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                ans += (1 << z);
            }
            z--;
        }
        return ans;
        
    }
};