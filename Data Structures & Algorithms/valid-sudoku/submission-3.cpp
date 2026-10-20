class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        unordered_set<std::string> seen;

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char val = board[r][c];

                // Skip empty cells
                if (val == '.') continue;

                // Create unique string tags for row, col, and 3x3 sub-box
               string rowTag = std::to_string(val) + " in row " + to_string(r);
               string colTag = std::to_string(val) + " in col " + to_string(c);
                string boxTag = std::to_string(val) + " in box " + to_string(r / 3) + "-" + std::to_string(c / 3);

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