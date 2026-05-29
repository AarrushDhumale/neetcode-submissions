class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int>counts;
        for(int i = 0; i < nums.size(); i++){
            counts[nums[i]]++;
        }

        vector<int>ans;

        for(auto i = counts.begin(); i != counts.end(); i++){
            if((i->second) > (nums.size() / 3)){
                ans.push_back(i->first);
            }
        }

        return ans;
    }
};