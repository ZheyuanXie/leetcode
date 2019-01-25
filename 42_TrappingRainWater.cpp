// 12 ms (27.57%)
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        vector<int> left;
        vector<int> right;
        int max = 0;
        int max2 = 0;
        for (int i = 0; i < height.size(); i++) {
            left.push_back(max);
            if (height[i] > max)
                max = height[i];
            right.insert(right.begin(), max2);
            if (height[height.size() - 1 - i] > max2)
                max2 = height[height.size() - 1 -i];
        }
        int total = 0;
        for (int i = 0; i < height.size(); i++) {
            int max_water = (right[i] > left[i] ? left[i] : right[i]);
            int water = max_water - height[i];
            if (water > 0) total += water;
        }
        return total;
    }
};