class Solution {
private:
    vector<int> findNextSmallerEleIdx(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }

        return ans;
    }

    vector<int> findPreviousSmallerEleIdx(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }

        return ans;
    }

    vector<int> findNextGreaterEleIdx(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }

        return ans;
    }

    vector<int> findPreviousGreaterEleIdx(const vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                ans[i] = st.top();
            }
            st.push(i);
        }

        return ans;
    }

    long long sumSubArrayMins(const vector<int>& nums) {
        vector<int> nse = findNextSmallerEleIdx(nums);
        vector<int> pse = findPreviousSmallerEleIdx(nums);
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int left = i - pse[i];
            int right = nse[i] - i;

            long long freq = left * right * 1LL;
            long long val = freq * nums[i] * 1LL;
            sum += val;
        }

        return sum;
    }

    long long sumSubArrayMaxs(const vector<int>& nums) {
        vector<int> nge = findNextGreaterEleIdx(nums);
        vector<int> pge = findPreviousGreaterEleIdx(nums);
        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            int left = i - pge[i];
            int right = nge[i] - i;

            long long freq = left * right * 1LL;
            long long val = freq * nums[i] * 1LL;
            sum += val;
        }

        return sum;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        return (sumSubArrayMaxs(nums) - sumSubArrayMins(nums));
    }
};