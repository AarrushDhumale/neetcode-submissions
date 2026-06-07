class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0;
        unordered_set<char>mp;
        int left = 0;

        for(int right = 0; right < s.length(); right++){
            while(mp.find(s[right]) != mp.end()){
               mp.erase(s[left]);
               left++; 
            }
            mp.insert(s[right]);
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
};
