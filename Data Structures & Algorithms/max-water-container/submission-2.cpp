class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxWater = 0;

        while (left < right) {
            int width = right - left;
            int currentHeight = min(height[left], height[right]);
            maxWater = max(maxWater, width * currentHeight);

            // Move the pointer with the shorter height inward
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};