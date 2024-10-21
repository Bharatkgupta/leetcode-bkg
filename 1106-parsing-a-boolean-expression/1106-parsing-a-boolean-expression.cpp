class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> optr;
        stack<char> values;
        for(const char& ch : expression) {
            if(ch == ',') {
                continue;
            } else if(ch == 't' || ch == 'f' || ch == '(') {
                values.push(ch);
            } else if(ch == '!' || ch == '&' || ch == '|') {
                optr.push(ch);
            } else {
                char opt = optr.top();
                optr.pop();
                bool exp = values.top() == 't';
                while(values.top() != '(') {
                    char val = values.top();
                    values.pop();
                    if(opt == '!') {
                        exp = !exp;
                    } else if(opt == '&') {
                        exp = exp && (val == 't');
                    } else {
                        exp = exp || (val == 't');
                    }
                }
                values.pop();
                values.push((exp ? 't' : 'f'));
            }
        }
        return values.top() == 't';
    }
};