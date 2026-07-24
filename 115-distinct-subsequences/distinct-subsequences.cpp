class Solution {
public:
    long long f(string& s, string& t, int i, int j,
                vector<vector<long long>>& dp) {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i] == t[j]) {
            return dp[i][j] = f(s, t, i - 1, j - 1, dp) + f(s, t, i - 1, j, dp);
        }
        return dp[i][j] = f(s, t, i - 1, j, dp);
    }

    int numDistinct(string s, string t) {
        int i = s.size();
        int j = t.size();
        vector<vector<long long>> dp(i, vector<long long>(j, -1));
        return f(s, t, i - 1, j - 1, dp);
    }
};

// class Solution {
// public:
//     long long f(string &s, string &t, int i, int j, vector<vector<long long>>
//     &dp) {

//         if (j < 0) return 1;
//         if (i < 0) return 0;

//         if (dp[i][j] != -1) return dp[i][j];

//         if (s[i] == t[j]) {
//             return dp[i][j] = f(s, t, i - 1, j - 1, dp)
//                             + f(s, t, i - 1, j, dp);
//         }

//         return dp[i][j] = f(s, t, i - 1, j, dp);
//     }

//     int numDistinct(string s, string t) {

//         int n = s.size();
//         int m = t.size();

//         vector<vector<long long>> dp(n, vector<long long>(m, -1));

//         return f(s, t, n - 1, m - 1, dp);
//     }
// };