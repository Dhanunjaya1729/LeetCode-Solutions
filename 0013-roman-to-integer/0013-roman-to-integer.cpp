class Solution {
public:
    int romanToInt(string s) {
        int total = 0;
        int prev_val = 0;

        for(char c: s|views::reverse){
            int curr_val = 0;

            switch(c){
                case 'I': curr_val = 1; break;
                case 'V': curr_val = 5; break;
                case 'X': curr_val = 10; break;
                case 'L': curr_val = 50; break;
                case 'C': curr_val = 100; break;
                case 'D': curr_val = 500; break;
                case 'M': curr_val = 1000; break;
            }

            total = (curr_val < prev_val) ? total - curr_val: total + curr_val;
            prev_val = curr_val;
        }
        return total;
    }
};