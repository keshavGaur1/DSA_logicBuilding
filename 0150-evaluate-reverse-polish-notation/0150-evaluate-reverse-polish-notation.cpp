class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int> st;

        for (string c : s) {
            if (c != "+" && c != "-" && c != "*" && c != "/") {
                st.push(stoi(c));
            } else {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int res = 0;

                if (c == "+")
                    res = a + b;
                else if (c == "-")
                    res = a - b;
                else if (c == "*")
                    res = a * b;
                else if (c == "/")
                    res = a / b;
                st.push(res);
            }
        }
        return st.top();
    }
};