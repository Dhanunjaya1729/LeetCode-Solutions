class Solution {
private:
    static bool isMatched(const char open, const char close) {
        if ((open == '(' && close == ')') || (open == '[' && close == ']') ||
            (open == '{' && close == '}')) {
            return true;
        }
        return false;
    }

public:
    bool isValid(string s) {
        stack<char> st;

        for (const auto& c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            } else {
                if (st.empty()) {
                    return false;
                }
                char ch = st.top();
                st.pop();
                if (!isMatched(ch, c)) {
                    return false;
                }
            }
        }
        return st.empty();
    }
};