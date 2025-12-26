class Solution {
public:
    int pivotInteger(int n) {
        int sum =0;
        for(int i=1;i<=n;i++){
            sum+=i;
        }
        // if(n==1)return 1;
        int x=0;
        for(int i=1;i<=n;i++){
            x+=i;
            if(x==sum){
                return i;
            }
            sum-=i;
        }
        return -1;
    }
};