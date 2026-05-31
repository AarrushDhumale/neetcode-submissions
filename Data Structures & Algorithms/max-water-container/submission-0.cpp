class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;
        int area = 0;
        
        int left = 0;
        int right = heights.size()-1;

        while(left < right){
            area = (right - left) * min(heights[right], heights[left]);
            if(area > max_area) max_area = area;
            if(min(heights[right], heights[left]) == heights[right]) right--;
            else left++;
        }

        return max_area;

    }
};
