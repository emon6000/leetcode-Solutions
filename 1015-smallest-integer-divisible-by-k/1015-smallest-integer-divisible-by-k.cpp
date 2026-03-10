class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }
         int x = 0;
        for (int i = 1; i <= k; i++) {
            x = (x * 10 + 1) % k;
            if (x == 0) {
                return i;
            }
        }
        return -1;
    }
};