class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>left(n),right(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            if(st.empty()){
                left[i]=0;
                st.push(i);
            }
            else{
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                left[i]=st.empty()?0:st.top()+1;
                st.push(i);
            }
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                right[i]=n-1;
                st.push(i);
            }
            else{
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                right[i]=st.empty()?n-1:st.top()-1;
                st.push(i);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(right[i]-left[i]+1)*heights[i]);
        }
        return ans;

    //   int l=0,r=0;
    //   int ans=0;
    //   int sz=heights.size();
    //   for(int i=0;i<sz;i++){
    //     if(i!=(sz-1)){
    //         for(int j=i+1;j<sz;j++){
    //             if(heights[j]<heights[i]){
    //                 r=j-1;
    //                 break;
    //             }
    //             if(j==sz-1){
    //                 r=sz-1;
    //             }
    //         }
    //     }
    //     else{
    //         r=sz-1;
    //     }
    //     if(i!=0){
    //         for(int j=i-1;j>=0;j--){
    //             if(heights[j]<heights[i]){
    //                 l=j+1;
    //                 break;
    //             }
    //             if(j==0){
    //                 l=0;
    //             }
    //         }
    //     }
    //     else{
    //         l=0;
    //     }
        
    //     if((l==0 && r==0)||r<l ) ans=max(ans,heights[i]);
    //     else ans=max(ans,(r-l+1)*heights[i]);
    //     // cout<<l<<" "<<r<<" "<<ans<<endl;
    //     l=0,r=0;
    //   }
    //   return ans;  
    }
};