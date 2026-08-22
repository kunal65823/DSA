class Solution {
public:
    bool checkDivisibility(int n) {
        int temp = n;
        int sum = 0;
        int multiplication = 1;

        while (temp > 0) {
            int digit = temp % 10;

            sum += digit;
            multiplication *= digit;

            temp /= 10;
        }

        return n % (sum + multiplication) == 0;
    }
};