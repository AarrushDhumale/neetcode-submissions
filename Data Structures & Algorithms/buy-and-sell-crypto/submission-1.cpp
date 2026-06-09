class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_num = prices[0];
        int max_price = 0;

        for(int price: prices){
            max_price = max(max_price, price - min_num);
            min_num = min(min_num, price);
        }
        return max_price;
    }
};
