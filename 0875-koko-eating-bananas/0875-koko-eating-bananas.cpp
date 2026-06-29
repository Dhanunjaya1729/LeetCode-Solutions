class Solution {
private:
    bool canFinish(const int mid, const vector<int>& nums, const int h){
        long long time = 0;
        for(auto i: nums){
            time += ((i + mid -1)/mid);
            if(time > h){
                return false;
            }
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        long long high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while(low <= high){
            int mid = low + (high - low)/2;
            bool isPossible = canFinish(mid, piles, h);

            if(isPossible){
                high = mid - 1;
                ans = mid;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};