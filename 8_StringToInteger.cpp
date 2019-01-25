class Solution {
private:
    bool isDigit(char c) {
        return (c >= '0' && c <= '9');
    } 
    bool isWhiteSpace(char c) {
        return (c == ' ');
    }
    bool isMinus(char c) {
        return (c == '-');
    }
    bool isPlus(char c) {
        return (c == '+');
    }
public:
    int myAtoi(string str) {
        int number = 0;
        bool digit_found = false;
        bool sign = true;
        for (string::iterator it = str.begin(); it != str.end(); it++) {
            if (!digit_found) {
                if (isWhiteSpace(*it)) continue;
                if (isPlus(*it) || isMinus(*it)) {
                    digit_found = true;
                    sign = isPlus(*it);
                } else if (isDigit(*it)) {
                    digit_found = true;
                    number = number * 10 + (*it - '0');
                } else return 0;
            } else {
                if (isDigit(*it)) {
                    int digit = *it - '0';
                    if (sign) {
                        if (number > INT_MAX / 10 || (number == INT_MAX / 10 && digit > 7))
                            return INT_MAX;
                    } else {
                        if (-number < INT_MIN / 10 || (-number == INT_MIN / 10 && digit > 8))
                            return INT_MIN;
                    }
                    number = number * 10 + digit;
                } else {
                    break;
                }
            }
        }
        if (!sign) number = -number;
        return number;
    }
};