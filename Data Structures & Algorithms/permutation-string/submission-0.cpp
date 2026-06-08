class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length() < s1.length()) return false;
        
        vector<int>freq(26, 0);
        for(int i = 0; i < s1.length(); i++){
            freq[s1[i] - 'a']++;
        }

        for(int i = 0; i < s2.size() - s1.size() + 1; i++){
            vector<int>temp(26, 0);
            for(int j = 0; j < s1.size(); j++){
                temp[s2[i+j] - 'a']++;
            }
            if(temp == freq) return true;
        }
        return false;
    }
};
