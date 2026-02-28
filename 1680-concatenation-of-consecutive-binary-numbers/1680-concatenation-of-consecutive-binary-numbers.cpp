class Solution {
public:
    int concatenatedBinary(int n) {
        // long mod = 1000000007;
        long mod = 1e9 + 7;
        long ans = 0;
        long l = 0;
        for (long i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) {
                l++;
            }
            ans = ((ans << l) | i) % mod;
        }
        return ans;
    }
};