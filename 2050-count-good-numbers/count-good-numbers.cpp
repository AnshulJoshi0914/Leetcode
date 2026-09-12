class Solution {
private:

    long long mod = 1000000007;

    long long power(long long x, long long n) {
        long long ans = 1;

        while (n > 0) {

            if (n % 2 == 1) {
                ans = (ans * x) % mod;
            }

            x = (x * x) % mod;
            n /= 2;
        }

        return ans;
    }

public:

    int countGoodNumbers(long long n) {

        long long even = (n + 1) / 2;
        long long odd = n / 2;

        long long ans = (power(5, even) * power(4, odd)) % mod;

        return ans;
    }
};