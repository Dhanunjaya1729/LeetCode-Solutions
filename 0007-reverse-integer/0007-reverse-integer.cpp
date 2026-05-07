class Solution {
private:
    int reverse_num(int n) {
        int rev_num = 0;
        while (n != 0) {
            int last_digit = n % 10;
            if (rev_num <= (INT_MAX - last_digit) / 10) {
                rev_num = (rev_num * 10) + last_digit;
                n /= 10;
            } else {
                return 0;
            }
        }
        return rev_num;
    }

public:
    int reverse(int n) {
        if (n == INT_MIN) {
            return 0;
        }
        if (n > 0) {
            return reverse_num(n);
        } else {
            return -reverse_num(-n);
        }
    }
};