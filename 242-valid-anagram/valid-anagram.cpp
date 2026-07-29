class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // for(int i=0;i<s.size();i++){
        //     if(s!=t)return false;
        // }
        // return true;
        vector<int>ans(26,0);
        for(int i=0;i<s.size();i++){
            ans[s[i]-'a']++;
            ans[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(ans[i]!=0) return false;
        }
        return true;
    }
};