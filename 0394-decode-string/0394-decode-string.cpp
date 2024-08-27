class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> numst;
        int i=0, j=0;
        while(i<s.length()) {
            if(s[i]-'0' > 0 && s[i]-'0' <= 9) {
                if(j != i) {
                    st.push(s.substr(j, i-j));
                }
                int e = i+1;
                while(s[e] != '[') {
                    e++;
                }
                numst.push(stoi(s.substr(i, e-i)));
                st.push("[");
                j=e+1;
                i=e;
            }
            if(s[i] == ']') {
                if(j != i) {
                    st.push(s.substr(j, i-j));
                }
                string temp = "";
                while(st.top() != "[") {
                    temp = st.top() + temp;
                    st.pop();
                }
                st.pop();
                int freq = numst.top();
                numst.pop();
                while(freq) {
                    st.push(temp);
                    freq--;
                }
                j=i+1;
            }
            i++;
        }
        if(j != i) {
            st.push(s.substr(j, i-j));
        }
        string ans = "";
        while(!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};