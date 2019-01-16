// Brute Force (948ms, 13.28%)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxarea = 0;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i+1; j < height.size(); j++) {
                int area = min(height[i], height[j]) * abs(i-j);
                if (area > maxarea) maxarea = area;
            }
        }
        return maxarea;
    }
};