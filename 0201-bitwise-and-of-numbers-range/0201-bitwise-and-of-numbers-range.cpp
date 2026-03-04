class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        int shifts = 0;
        while (l < r) {
            l >>= 1;
            r >>= 1;
            shifts++;
        }
        return l << shifts;
    }
};