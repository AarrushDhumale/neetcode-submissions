class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod1 = 1; // Product of non-zero elements
        int zeroCount = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(nums[i] != 0){
                prod1 = prod1 * nums[i];
            } else {
                zeroCount++;
            }
        }

        vector<int> ans(n, 0); // Initialize all to 0 by default
        
        // If there is more than 1 zero, every answer is 0. 
        // We only need to do math if there is 0 or 1 zero.
        if (zeroCount > 1) {
            return ans; 
        }

        for(int i = 0; i < n; i++){
            if(zeroCount == 1){
                // If there's exactly one zero, ONLY that zero's spot gets the product.
                if(nums[i] == 0){
                    ans[i] = prod1;
                }
            } else {
                // If there are no zeros, we can safely divide.
                ans[i] = prod1 / nums[i];
            }
        }

        return ans;
    }
};