class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans(m, -1);

        for(int i = 0; i < m; i++){
            stack<int> st;
            for(int j = n - 1; j >= 0; j--){
                int currentElement = nums2[j];
                while(!st.empty() && st.top() <= currentElement){
                    st.pop();
                }
                if(st.empty()){
                    ans[i] = -1;
                }
                else{
                    if(nums1[i] == nums2[j]){
                        ans[i] = st.top();
                        break;
                    }
                }
                st.push(currentElement);
            }
        }
        return ans;
    }
};