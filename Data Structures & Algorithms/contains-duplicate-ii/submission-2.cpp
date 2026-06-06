class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        //if(nums.size() < k) return false;

        // int i = 0;
        // int j = i+k;
        int i = 0;
        while(k > 0){
            //int i = 0;
            int j = i + k;

            if(j >= nums.size()){
                i = 0;
                k--;
                continue;
            }

            if(nums[i] == nums[j])return true;
            else{
                i++;
            }
        }
        return false;
    }
};