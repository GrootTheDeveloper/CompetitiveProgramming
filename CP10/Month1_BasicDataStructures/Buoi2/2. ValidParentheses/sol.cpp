class Solution {
public:
    bool isValid(string s) {
        stack <char> mystack; 
        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                mystack.push(s[i]); 
            }
            else if (s[i] == ')') {
                if (mystack.empty() == true || mystack.top() != '(') {
                    return false;
                }
                mystack.pop();
            }
            else if (s[i] == ']') {
                if (mystack.empty() == true || mystack.top() != '[') {
                    return false;
                }
                mystack.pop(); 
            }
            else {
                if (mystack.empty() == true || mystack.top() != '{') {
                    return false;
                }
                mystack.pop();
            }
        }
        if (mystack.empty() == false) {
            return false;
        }
        return true; 
    }
};