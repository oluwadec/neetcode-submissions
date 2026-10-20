class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        std::unordered_set<std::string> seen;

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char val = board[r][c];

                // Skip empty cells
                if (val == '.') continue;

                // Create unique string tags for row, col, and 3x3 sub-box
                std::string rowTag = std::to_string(val) + " in row " + std::to_string(r);
                std::string colTag = std::to_string(val) + " in col " + std::to_string(c);
                std::string boxTag = std::to_string(val) + " in box " + std::to_string(r / 3) + "-" + std::to_string(c / 3);

                // If any tag is already in the set, a duplicate exists
                if (seen.count(rowTag) || seen.count(colTag) || seen.count(boxTag)) {
                    return false;
                }

                // Add all three tags to the set
                seen.insert(rowTag);
                seen.insert(colTag);
                seen.insert(boxTag);
            }
        }

        return true;
    }
};