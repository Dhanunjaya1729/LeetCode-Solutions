class Solution {
private:
    bool isValidAnagram(string s, string t){
        int n = s.size();
        if(n != t.size()){
            return false;
        }
        vector<int> v(26, 0);
        for(int i = 0; i < n; i++){
            v[s[i] - 'a']++;
            v[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(v[i] != 0){
                return false;
            }
        }
        return true;
    }

public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i = 1; i < words.size(); i++){
            if(!isValidAnagram(ans.back(), words[i])){
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};