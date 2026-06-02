#include <iostream>
#include <vector>
#include <sstream>

class Solution {
public:
    string simplifyPath(string path) {
        // We use a vector as a stack so we can easily iterate from bottom to top at the end
        vector<string> stack; 
        stringstream ss(path);
        string token;

        // getline with '/' splits the string automatically. 
        // "/a//b/" becomes ["", "a", "", "b", ""]
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                // Ignore empty strings (caused by //) and current directory (.)
                continue;
            } 
            else if (token == "..") {
                // Go up a directory by popping the stack
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } 
            else {
                // It's a valid directory name, push it
                stack.push_back(token);
            }
        }

        // Rebuild the final simplified path
        string res = "";
        for (const string& dir : stack) {
            res += "/" + dir;
        }

        // Edge case: if the stack was completely emptied, return root "/"
        return res.empty() ? "/" : res;
    }
};