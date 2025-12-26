class Solution {
public:
    int bestClosingTime(string customers) {
        int y=0,n=0;
        int l = customers.size();
        for(int i=0;i<l;i++){
            if(customers[i]=='Y'){
                y++;
            }
            else{
                n++;
            }
        }
        if(y==l){
            return l;
        }
        else if(n==l){
            return 0;
        }
        else{
            int ans=0;
            int p=l,py=0,pn=0;
            for(int i=0;i<l;i++){
                if(customers[i]=='Y'){
                    py++;
                }
                else{
                    pn++;
                }
                int pl=(y-py+pn);
                if(pl<p){
                    p =pl;
                    ans=i+1;
                }
            }
            if(y<=p){
            return 0;
            }
            return ans;
        }
    }
};