class Solution {
public:
    int minAddToMakeValid(string s) {
        int opening = 0;
        int closed = 0;
        for (char ch : s) {
            if (ch == '(') {
                opening++;
            } else {
                if (opening > 0 && ch == ')') {
                    opening--;
                } else {
                    closed++;
                }
            }
        }
        return opening +closed;
    }
};