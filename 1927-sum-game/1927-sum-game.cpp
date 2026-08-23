class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                if (i < n / 2)
                    leftQ++;
                else
                    rightQ++;
            } else {
                if (i < n / 2)
                    leftSum += num[i] - '0';
                else
                    rightSum += num[i] - '0';
            }
        }

        // Odd number of '?' -> Alice wins
        if ((leftQ + rightQ) % 2 == 1)
            return true;

        // Check whether Bob can make both sums equal
        return leftSum - rightSum != (rightQ - leftQ) / 2 * 9;
    }
};