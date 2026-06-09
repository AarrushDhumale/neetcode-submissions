class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        int left = 0;
        int size = 1;
        int right = 1;

        while(size < n+1 && right < n){
            if(right == n-1){
                max_profit = max(max_profit, prices[right] - prices[left]);
                left = 0;
                size++;
                right = left + size;
                continue;
            }
            max_profit = max(prices[right] - prices[left], max_profit);
            left++;
            right++;
        }

        return max_profit;
        
    }
};
