class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> hash(26, 0);
        for(auto it: s){
            hash[it-'a']++;
        }

        for(auto it: t){
            hash[it-'a']--;
        }

        for(auto it: hash){
            if(it != 0) return false;
        }

        return true;
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s==t){
        //     return true;
        // }
        // else{
        //     return false;
        // }
    }
};