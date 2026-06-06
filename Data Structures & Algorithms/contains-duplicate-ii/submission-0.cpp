class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = i+1; j < nums.size(); j++){
                if(nums[j] == nums[i]){
                    if(abs(j-i) <= k) return true;
                }
            }
        }
        return false;
    }
};