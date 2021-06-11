#include <iostream>
#include <vector>
using namespace std;

// time comp => O(n*m)
int const dXdY[8][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

bool validPoints(int x, int y, int n, int m){
    return (x >= 0 && x < n && y >= 0 && y < m);
}

bool helper(vector<vector<char> > &board, vector<vector<bool> > &visited, string &word, int x, int y, int wordIndex, int n, int m){
    if(wordIndex == 11){
        return true;
    }
    visited[x][y] = true;
    bool ans = false;
    
    for(int i=0; i<8; i++){
        int newX = x + dXdY[i][0];
        int newY = y + dXdY[i][1];
        if(validPoints(newX, newY, n, m) && board[newX][newY] == word[wordIndex] && !visited[newX][newY]){
            ans = ans | helper(board, visited, word, newX, newY, wordIndex+1, n, m);
        }
    }
    visited[x][y] = false;
    return ans;
}

bool hasPath(vector<vector<char> > &board, int n, int m) {
    string word = "CODINGNINJA";
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == word[0]){
                bool ans = helper(board, visited, word, i, j, 1, n, m);
                if(ans)
                    return ans;
            }
        }
    }
    return false;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char> > board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }
    cout << (hasPath(board, n, m) ? 1 : 0);
}
