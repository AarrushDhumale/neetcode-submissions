class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>res(temperatures.size());
        res[n-1] = 0;

        for(int i = 0; i < temperatures.size() - 1; i++){
            int count = 0;
            for(int j = i+1; j < temperatures.size(); j++){
                if(temperatures[j] > temperatures[i]){
                    count = j-i;
                    res[i] = count;
                    break;
                }
            }
        }

        return res;
    }
};
