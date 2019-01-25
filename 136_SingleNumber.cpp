// Sum
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> seen;
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (seen.find(nums[i]) == seen.end()) {
                seen.insert(nums[i]);
                sum1 += nums[i];
            }
            sum2 += nums[i];
        }
        return sum1 * 2 - sum2;
    }
};

// XOR (8ms)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i = nums.size()-1; i > 0; i--)
            nums[i-1] ^= nums[i];
        return nums[0];
    }
};