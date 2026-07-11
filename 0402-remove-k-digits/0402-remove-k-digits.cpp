class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for(char digit: num){
            while(!st.empty() && k > 0 && st.top() > digit){
                st.pop();
                k--;
            }
            st.push(digit);
        }

        while(!st.empty() && k > 0){
            st.pop();
            k--;
        }

        if(st.empty()){
            return "0";
        }

        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        while(ans.size() > 0 && ans.back() == '0'){
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());

        if(ans.empty()){
            return "0";
        }
        return ans;
    }
};