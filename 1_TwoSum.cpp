class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mapping;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            mapping[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (mapping.find(target - nums[i]) != mapping.end()) {
                if (mapping[target-nums[i]] != i) {
                    res.push_back(min(mapping[target-nums[i]],i));
                    res.push_back(max(mapping[target-nums[i]],i));
                    return res;
                }
            }
        }
        return res;
    }
};