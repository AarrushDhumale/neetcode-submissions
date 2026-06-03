class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0; // Quick edge case

        int left = 1; // Start at 1 to avoid division by zero issues later
        int right = x;
        int res = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2; // Fixed overflow risk

            // Use division instead of multiplication to prevent overflow
            if (mid == x / mid) {
                return mid;
            }
            else if (mid < x / mid) {
                // mid is too small! Move the left pointer UP.
                left = mid + 1;
                res = mid; // Save mid because it's a valid floor candidate
            } 
            else {
                // mid is too big! Move the right pointer DOWN.
                right = mid - 1;
            }
        }
        return res;
    }
};