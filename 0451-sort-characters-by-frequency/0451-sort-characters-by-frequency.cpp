class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqMap;
        for (char ch : s) {
            freqMap[ch]++;
        }

        vector<pair<int, char>> freqVec;
        for (auto& it : freqMap) {
            freqVec.push_back({it.second, it.first});
        }

        sort(freqVec.begin(), freqVec.end(), [](const pair<int, char>& a, const pair<int, char>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second < b.second;
        });

        string ans = "";
        for (auto& p : freqVec) {
            ans.append(p.first, p.second); 
        }

        return ans;
    }
};