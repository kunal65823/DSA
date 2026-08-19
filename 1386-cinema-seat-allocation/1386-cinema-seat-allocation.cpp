class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;

        // Store reserved seats using bitmask
        for (auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];

            if (col >= 2 && col <= 9) {
                mp[row] |= (1 << col);
            }
        }

        // Rows with no reservations can fit 2 families
        int ans = (n - mp.size()) * 2;

        for (auto& [row, mask] : mp) {
            bool left = (mask & 0b00000111100) == 0;   // seats 2-5
            bool middle = (mask & 0b00011110000) == 0; // seats 4-7
            bool right = (mask & 0b01111000000) == 0;  // seats 6-9

            if (left && right) {
                ans += 2;
            } 
            else if (left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};