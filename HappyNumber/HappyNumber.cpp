class Solution {
public:
    bool isHappy(int n) {
        int num = 0;
        int temp = 0;
        bool flag = true;
        while (flag) {
            num = 0;
            while (n) {
                temp = n % 10;
                num += temp * temp;
                n /= 10;
            }
            n = num;
            if (n == 1 || n == 4) {
                flag = false;
            }
        }
        return n == 1;
    }
};