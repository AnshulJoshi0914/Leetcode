class Solution {
public:
    string say(string n) {
        int k = n.size();
        if (k == 0)
            return "1";
        string ans = "";
        for (int i = 0; i < k; i++) {
            int cnt = 1;
            while (i < k - 1 && n[i] == n[i + 1]) {
                i++;
                cnt++;
            }

            ans += to_string(cnt);
            ans += n[i];
        }
        return ans;
    }
    string countAndSay(int n) {
        string ans = "";
        for (int i = 0; i < n; i++) {
            ans = say(ans);
        }
        return ans;
    }
};