class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int count = 0;
        int prev = 0;
        
        for(int i = 1; i < intervals.size(); i++) {
            if(intervals[i][0] < intervals[prev][1]) {
                count++;
                if(intervals[i][1] < intervals[prev][1]) {
                    prev = i;
                }
            } else {
                prev = i;
            }
        }
        return count;
    //     vector<vector<int>>vp;
    //     vp=intervals;
    //     int l=vp.size();
    //     sort(vp.rbegin(), vp.rend(), [](const auto &a, const auto &b)
    //      { return (a[1] > b[1]); });
    // int c=0;
    // vector<vector<int>>ans;
    // ans.push_back({vp[0][0],vp[0][1]});
    // int track = 0;
    //     for (int i = 1; i < l; i++)
    //     {
    //     if(vp[i][0]<ans[track][1]){
    //         c++;
    //     }
    //     else{
    //         ans.push_back({vp[i][0],vp[i][1]});
    //         track++;
    //     }
    //     }
    //     int x = l - ans.size();
    //     return (x);
    }
};