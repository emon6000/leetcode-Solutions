class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        int result = 0;
        
        while (l > 0 && r > 0) {
            int msbl = 31 - __builtin_clz(l);
            int msbr = 31 - __builtin_clz(r);
            
            if (msbl != msbr) {
                break;
            }
            
            int msb_val = 1 << msbl;
            result += msb_val;
            
            l -= msb_val;
            r -= msb_val;
        }
        
        return result;
    }
};