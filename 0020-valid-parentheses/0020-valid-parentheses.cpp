class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2) {
            return false;
        }
        stack<char> Pstack;
        for(const auto& c: s) {
            if(c == '(' || c == '{' || c == '[') {
                Pstack.push(c);
            } else if(c == ')' && Pstack.size() != 0 && Pstack.top() == '(') {
                Pstack.pop();
            } else if(c == '}' && Pstack.size() != 0 && Pstack.top() == '{') {
                Pstack.pop();
            } else if(c == ']' && Pstack.size() != 0 && Pstack.top() == '[') {
                Pstack.pop();
            } else {
                return false;
            }
        }
        if(Pstack.size()) {
            return false;
        }
        return true;
    }
};