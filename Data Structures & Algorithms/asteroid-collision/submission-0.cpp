class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; 
        
        for (int ast : asteroids) {
            bool destroyed = false;
            
            // Handle collisions: 
            // 1. Stack is not empty
            // 2. Current asteroid is moving Left (-)
            // 3. Top of stack is moving Right (+)
            while (!st.empty() && ast < 0 && st.back() > 0) {
                
                // Stack asteroid is smaller -> it explodes
                if (abs(ast) > st.back()) {
                    st.pop_back(); 
                    continue; // Keep checking the next asteroid down in the stack
                } 
                // Both are the same size -> both explode
                else if (abs(ast) == st.back()) {
                    st.pop_back(); 
                }
                
                // If we reach here, the current incoming asteroid was either 
                // smaller than the stack top, or equal. Either way, it gets destroyed.
                destroyed = true; 
                break; 
            }
            
            // If the incoming asteroid survived all collisions, push it to the stack
            if (!destroyed) {
                st.push_back(ast);
            }
        }
        
        return st;
    }
};