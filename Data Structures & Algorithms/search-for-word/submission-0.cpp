class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (dfs(board, word, r, c, 0)) return true;
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, string& word, int r, int c, int idx) {
        if (idx == word.size()) return true; // matched all characters

        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() 
            || board[r][c] != word[idx]) {
            return false;
        }

        // mark as visited by temporarily changing the character
        char temp = board[r][c];
        board[r][c] = '#';

        bool found = dfs(board, word, r + 1, c, idx + 1) ||
                     dfs(board, word, r - 1, c, idx + 1) ||
                     dfs(board, word, r, c + 1, idx + 1) ||
                     dfs(board, word, r, c - 1, idx + 1);

        // backtrack: restore the original character
        board[r][c] = temp;

        return found;
    }
};