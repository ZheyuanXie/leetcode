// 20 ms
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> sol(nums.size(),0);
        for (int i = 0; i < nums.size(); i++) {
            sol[i] = nums[((i-k)+nums.size()*(k/nums.size()+1)) % nums.size()];
        }
        nums = sol;
    }
};