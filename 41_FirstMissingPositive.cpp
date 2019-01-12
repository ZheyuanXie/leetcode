//4 ms
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> missing(0,1);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= 0) continue;
            if (nums[i] > missing.size())
                missing.resize(nums[i],1);
            missing[nums[i]-1] = 0;
        }
        for (int i = 0; i < missing.size(); i++) {
            if (missing[i] == 1) return i+1;
        }
        return missing.size()+1;
    }
};