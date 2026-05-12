class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        
        int ans = 0;
        int rem = 0;
        
        for (const auto& task : tasks) {
            int t = task[0];
            int t2 = task[1];
            
            if (rem < t2) {
                ans += (t2 - rem);
                rem = t2 - t;
            } else {
                rem = rem - t;
            }
        }
        
        return ans;
    }
};
// class Solution {
// public:
//     int minimumEffort(vector<vector<int>>& tasks) {
//         int n = tasks.size();
//         vector<pair<int, int>> vp;
//         for (int i = 0; i < n; i++) {
//             int x = tasks[i][0];
//             int y = tasks[i][1];
//             int diff = y - x;
//             vp.push_back({diff, i});
//         }
//         sort(vp.rbegin(), vp.rend());
//         for (int i = 0; i < n; i++) {
//             cout << vp[i].first << " " << vp[i].second << endl;
//         }
//         int ans = 0, rem = 0;
//         for (int i = 0; i < n; i++) {
//             int y = vp[i].second;

//             int t = tasks[y][1];
//             int t2 = tasks[y][0];
//             cout << t << " " << t2 << endl;
//             if (rem < t) {
//                 ans += (t - rem);
//                 rem = t - t2;
//             } else {
//                 rem = rem - t2;
//             }
//         }
//         return ans;
//     }
// };