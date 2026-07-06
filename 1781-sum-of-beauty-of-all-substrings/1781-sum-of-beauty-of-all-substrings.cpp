class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;
        int n = s.size();

        for(int i = 0; i < n; i++){
            vector<int> freq(26, 0);
            int maxFreq = 0;

            for(int j = i; j < n; j++){
                int current_f = ++freq[s[j] - 'a'];
                maxFreq = max(maxFreq, current_f);

                int minFreq = n;
                for(int f: freq){
                    if(f > 0){
                        minFreq =  min(f, minFreq);
                    }
                }
                totalBeauty += maxFreq - minFreq;
            }
        }
        return totalBeauty;
    }
};