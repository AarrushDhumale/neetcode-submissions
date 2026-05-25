class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        
        // 1. Simplify map population
        for(int num : nums){
            um[num]++;
        }

        // 2. Correct vector declaration
        vector<pair<int, int>> count;
        
        // 3. Correct map iteration
        for(auto it = um.begin(); it != um.end(); it++){
            count.push_back({it->first, it->second});
        }

        // 4. Sort descending (highest frequency first)
        std::sort(count.begin(), count.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.second > b.second; 
        });

        // 5. Extract top K elements
        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(count[i].first);
        }

        return ans;
    }
};