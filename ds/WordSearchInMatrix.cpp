// write the cpp program to find the given word in a given matrix 

#include <iostream>
#include <vector>
#include <functional>
#include <string>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        function<bool(int, int, int)> dfs = [&](int i, int j,
                                                int index) -> bool {
            if (index == word.length())
                return true;
            if (i < 0 || j < 0 || i >= n || j >= m ||
                board[i][j] != word[index]) {
                return false;
            }
            char temp = board[i][j];
            board[i][j] = '#';

            bool found = dfs(i - 1, j, index + 1) || dfs(i, j+1, index + 1) ||
                         dfs(i , j-1, index + 1) || dfs(i + 1, j, index + 1);

            
            board[i][j]=temp;

            return found;
        };

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(i,j,0)) return true;
            }
        }
        return false;
    }
};
int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "ABCCED";
    Solution sol;
    if (sol.exist(board, word)) {
        cout << "Word found in the board" << endl;
    } else {
        cout << "Word not found in the board" << endl;
    }
    return 0;
}