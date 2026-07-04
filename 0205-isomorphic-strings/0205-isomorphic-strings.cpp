class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int lenS = s.size();
        if(lenS != t.size()){
            return false;
        }

        vector<int> mapS(256, 0), mapT(256, 0);

        for(int i = 0; i < lenS; i++){
            if(mapS[s[i]] !=  mapT[t[i]]){
                return false;
            }
            mapS[s[i]] = i + 1;
            mapT[t[i]] = i + 1;
        }

        return true;
    }
};