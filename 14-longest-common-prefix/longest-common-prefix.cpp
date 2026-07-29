class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        sort(strs.begin(),strs.end());
        string first=strs[0];
        string last=strs[n-1];
        string ans="";
        if(strs.empty()) return "";
        int minlength=min(first.size(),last.size());
        for(int i=0;i<minlength;i++){
           if(first[i]==last[i]){
               ans+=first[i];
           }
           else if(first[i]!=last[i]){
            break;
           }
        }
        return ans; 
    }
};