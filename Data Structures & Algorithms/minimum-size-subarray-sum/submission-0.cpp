class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int>sums(n+1);
        
        for(int i = 1; i < n+1; i++){
            sums[i] = sums[i-1] + nums[i-1];
        }

        if(sums[n] < target) return 0;

        int l = 0;
        int size = 1;
        int r = l + size;

        while(r < n+1 && size < n+1){
            if(sums[r] - sums[l] >= target) return size;
            
            if(r == n){
                l = 0;
                size++;
                r = size;
                continue;
            }
            l++;
            r++;
        }

        return -1;
    }
};