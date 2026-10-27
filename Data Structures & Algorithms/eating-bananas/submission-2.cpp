class Solution {
private:
    // Helper function to check if Koko can eat all bananas within 'h' hours at speed 'k'
    bool canEatInTime(const vector<int>& piles, int h, long long k) {
        long long totalHours = 0;
        for (int bananas : piles) {
            // Equivalent to ceil(bananas / k) using integer arithmetic to avoid float issues
            totalHours += (bananas + k - 1) / k;
        }
        return totalHours <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long left = 1;
        long long right = 0;
        
        // Find the maximum pile size to set our upper bound
        for (int bananas : piles) {
            right = max(right, (long long)bananas);
        }
        
        long long minSpeed = right;
        
        // Binary search for the minimum valid speed k
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            
            if (canEatInTime(piles, h, mid)) {
                minSpeed = mid;      // Record valid speed
                right = mid - 1;     // Try to find a smaller (slower) valid speed
            } else {
                left = mid + 1;      // Too slow, increase the speed
            }
        }
        
        return minSpeed;
    }
};