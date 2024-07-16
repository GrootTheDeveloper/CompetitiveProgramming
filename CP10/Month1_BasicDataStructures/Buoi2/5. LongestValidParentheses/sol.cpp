class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0; 
        stack <int> mystack;
        mystack.push(-1); 
        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] == '(') {
                mystack.push(i);
            }
            else {
                mystack.pop(); 
                if (mystack.empty() == true) {
                    mystack.push(i);
                }
                else {
                    ans = max(ans, i - mystack.top());
                }
            }
        }
        return ans; 
    }
};