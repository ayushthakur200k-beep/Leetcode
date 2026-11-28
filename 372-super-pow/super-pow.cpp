class Solution {
public:
    int modPow(int a, int b) {
        long long result = 1;

        while (b > 0) {
            if (b & 1)
                result = result * a % 1337;

            a = 1LL * a * a % 1337;
            b >>= 1;
        }

        return result;
    }

    int superPow(int a, vector<int>& b) {
        a %= 1337;

        long long result = 1;

        for (int digit : b) {
            result = modPow(result, 10);
            result = result * modPow(a, digit) % 1337;
        }

        return result;
    }
};