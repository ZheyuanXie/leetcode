//92 ms
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength = 0;
        int start = 0;
        int length = 0;
        vector<int> used(256,0);
        for (int i = 0; i < s.size(); i++) {
            if (used[(int)s[i]] == 0) { // the character is not used
                length++;
                used[(int)s[i]] = 1;    // mark as used
            } else {
                start++;
                i = start - 1;
                fill(used.begin(), used.end(), 0);
                length = 0;
            }
            if (length > maxlength) maxlength = length;
        }
        return maxlength;
    }
};