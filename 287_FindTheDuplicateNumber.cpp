class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
            if (seen.find(*it) == seen.end()) seen.insert(*it);
            else return *it;
        }
        return 0;
    }
};