#include <iostream>
#include <vector>
using namespace std;


// time comp => O(n*m)
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1}; 

void helper(vector<vector<char> > &board, vector<vector<bool> > &visited, int x, int y, int fromX, int fromY, char needColor, bool &ans, int n, int m) {
    if(x < 0 || x >= n || y < 0 || y >= m) 
        return;
    
    if (board[x][y] != needColor) 
        return;
    if (visited[x][y]) {
        ans = true;
        return;
    }
    visited[x][y] = true;
    
    for (int i = 0; i < 4; ++i) { 
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if (nextX == fromX && nextY == fromY) { 
            continue; 
        }
        helper(board, visited, nextX, nextY, x, y, needColor, ans, n, m);
    }
}

bool hasCycle(vector<vector<char> > &board, int n, int m) {
    bool ans = false;
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!visited[i][j]){
                helper(board, visited, i, j, -1, -1, board[i][j], ans, n, m);
            }
        }
    }
    return ans;
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
    cout << (hasCycle(board, n, m) ? "true" : "false");
}
