class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }

        string minStr = *min_element(strs.begin(), strs.end());
        string maxStr = *max_element(strs.begin(), strs.end());
        string ans;

        for(int i = 0; i < min(minStr.size(), maxStr.size()); i++){
            if(minStr[i] != maxStr[i]){
                break;
            }
            ans += minStr[i];
        }

        return ans;
    }
};