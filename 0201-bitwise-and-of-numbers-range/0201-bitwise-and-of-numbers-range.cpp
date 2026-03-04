// class Solution {
// public:
//     int rangeBitwiseAnd(int l, int r) {
//         int shifts = 0;
//         while (l < r) {
//             l >>= 1;
//             r >>= 1;
//             shifts++;
//         }
//         return l << shifts;
//     }
// };

// Brian Kernighan's Algorithm (Clearing the lowest set bit)

class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        while (r > l) {
            r &= (r - 1);
        }
        return r;
    }
};