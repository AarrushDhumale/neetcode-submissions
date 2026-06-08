class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        vector<int>freq(26, 0);
        vector<int>window(26, 0);

        for(int i = 0; i < s1.size(); i++){
            freq[s1[i] - 'a']++;
            window[s2[i] - 'a']++;
        }

        if(freq == window) return true;

        for(int i = 1; i < s2.size() - s1.size() + 1; i++){
           window[s2[i-1] - 'a']--;
           window[s2[i + s1.size() - 1] - 'a']++;
           
           if(window == freq) return true; 
        }
        return false;
    }
};
