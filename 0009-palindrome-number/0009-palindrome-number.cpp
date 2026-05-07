class Solution {
public:
    bool isPalindrome(int n) {
        if(n == 0){
            return true;
        }
        else if(n < 0){
            return false;
        }
        vector<int> v;
        while(n != 0){
            int digit = n % 10;
            v.push_back(digit);
            n /= 10;
        }
        int size = v.size();
        for(int i = 0; i < size/2; i++){
            if(v[i] != v[size - i - 1]){
                return false;
            }
        }
        return true; 
    }
};