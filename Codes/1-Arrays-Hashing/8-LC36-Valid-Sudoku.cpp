class Solution {
public:
    // Time: O(n^2) | Space: O(n^2) but here constant because n is fixed!
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int k = sqrt(n);
        vector<unordered_set<char>> rows(n), cols(n), subgrid(n);
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                char ch = board[i][j];
                if(ch == '.') continue;
                int subGridVal = (i/k)*k + j/k;
                if(rows[i].count(ch) || cols[j].count(ch) || 
                        subgrid[subGridVal].count(ch)) return false;
                rows[i].insert(ch); cols[j].insert(ch);
                subgrid[subGridVal].insert(ch);
            }
        }
        return true;
    }
};