class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        if (dividend == INT_MIN && divisor == INT_MIN) return 1;
        if (divisor == INT_MIN) return 0;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        long long ldividend = abs((long long)dividend);
        long long ldivisor = abs((long long)divisor);
        int result = 0;
        while (ldividend >= ldivisor) {
            long long temp_divisor = ldivisor;
            long long multiple = 1;
            while (ldividend >= (temp_divisor << 1)) {
                temp_divisor <<= 1;
                multiple <<= 1;
            }
            ldividend -= temp_divisor;
            result += multiple;
        }
        return result * sign;
    }
};
