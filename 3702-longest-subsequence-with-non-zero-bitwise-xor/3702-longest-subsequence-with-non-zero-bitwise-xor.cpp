class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        
        for (int x : nums) {
            xr ^= x;
        }

        // Entire array has non-zero XOR
        if (xr != 0)
            return nums.size();

        // XOR is zero, check if any non-zero element exists
        for (int x : nums) {
            if (x != 0)
                return nums.size() - 1;
        }

        // All elements are zero
        return 0;
    }
};