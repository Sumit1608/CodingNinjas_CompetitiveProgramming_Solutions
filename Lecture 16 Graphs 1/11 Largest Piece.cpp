#include <iostream>
#include <vector>
using namespace std;

// time comp => O(n^2)
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int helper(vector<vector<int> > &cake, vector<vector<bool> > &visited, int x, int y, int n){
    if(visited[x][y] ){
        return 0;
    }
    
    visited[x][y] = true;
    int count =1;
    for(int i=0; i<4; i++){
        int newX = x + dx[i];
        int newY = y + dy[i];
        if(newX >= 0 && newX <n && newY >= 0 && newY <n && cake[newX][newY] == 1){
            count += helper(cake, visited, newX, newY, n);
        }
    }
    return count;
}

int getBiggestPieceSize(vector<vector<int> > &cake, int n) {
    int ans = 0;
    vector<vector<bool> > visited(n, vector<bool>(n, false));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cake[i][j] == 1 && !visited[i][j]){
                ans = max(ans, helper(cake, visited, i, j, n));
            }
        }
    }
    return ans;
}


int main() {
    int n;
    cin >> n;
    vector<vector<int> > cake(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> cake[i][j];
        }
    }
    cout << getBiggestPieceSize(cake, n);
}
