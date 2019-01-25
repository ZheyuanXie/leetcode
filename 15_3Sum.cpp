// 1232ms solution with hash map
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, int> seen;   // a hash map to store seen elements
        vector<vector<int>> res;        // return value
        for (int i = 0; i < nums.size(); i++) {     // add everything to the hash map
            seen[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i+1; j < nums.size(); j++) {
                int comp = -(nums[i] + nums[j]);
                map<int, int>::const_iterator got = seen.find(comp);
                if (got != seen.end() && (*got).second > j) {
                    vector<int> triplet = {(*got).first,nums[i],nums[j]};
                    if (find(res.begin(), res.end(), triplet) == res.end())
                        res.push_back(triplet);
                }
            }
        }
        return res;
    }
};