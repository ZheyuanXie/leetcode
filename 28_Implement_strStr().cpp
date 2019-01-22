class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() == 0 && needle.size() == 0) return 0;
        int first_occurance = -1;
        for (int i = 0; i < haystack.size(); i++) {
            bool match = true;
            for (int j = 0; j < needle.size(); j++) {
                if (i+j >= haystack.size() || haystack[i+j] != needle[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                first_occurance = i;
                break;
            }
        }
        return first_occurance;
    }
};