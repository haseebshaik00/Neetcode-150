class Solution {
public:
    // Time: O(n^2) | Space: O(n^2) but here constant because n is fixed!
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int sqrtN = sqrt(n);
        vector<unordered_set<char>> rows(n), cols(n), grids(n);
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                char ch = board[i][j];
                if(ch == '.') continue;
                int gridVal = (i/sqrtN)*sqrtN + (j/sqrtN);
                if(rows[i].count(ch) || cols[j].count(ch) || grids[gridVal].count(ch)) return false;
                rows[i].insert(ch); cols[j].insert(ch); grids[gridVal].insert(ch);
            }
        }
        return true;
    }
};