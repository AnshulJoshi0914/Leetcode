class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;
            for (int j = i; j < n; j++) {
                freq[s[j]]++;

                int maxfreq = INT_MIN;
                int minfreq = INT_MAX;

                for (auto it:freq) {
                    maxfreq = max(maxfreq, it.second);
                    minfreq = min(minfreq, it.second);
                }

                sum += maxfreq - minfreq;
            }
        }

        return sum;
    }
};