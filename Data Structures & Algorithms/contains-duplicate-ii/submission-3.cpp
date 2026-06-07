class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        unordered_set<int> window;

        for (int i = 0; i < nums.size(); i++) {
            // 1. Maintain the window size
            // If our window has grown larger than k, remove the oldest element from the left
            if (i > k) {
                window.erase(nums[i - k - 1]);
            }

            // 2. Check for duplicates inside our current window
            // If the set already contains this number, we found a match within distance k!
            if (window.count(nums[i])) {
                return true;
            }

            // 3. Add the current number to the window
            window.insert(nums[i]);
        }

        return false;
    }
};