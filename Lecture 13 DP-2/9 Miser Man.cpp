#include <bits/stdc++.h>
using namespace std;

// time comp => O(n*m)
// Start from city i with bus number j   now j can vary from 1 to m
// We can go to next (i+1)th city using arr[i][j] fair and can switch to
// the (j-1)th, jth or (j+1)th bus to go to (i+2)th city form (i+1)th
// now calculte the fair will be required if we take the three available 
// bus options to us,  the minimum of them all will be our answer
/*
Example : n=5 m=5
1  3  1  2  6
10 2  5  4  15
10 9  6  7  1
2  7  1  5  3
8  2  6  1  9
output => 10   and the dp array is
11 13 10 11 15 
21 10 13 9 20 
14 11 8  9  5 
4  9  2  6  4 
8  2  6  1  9
*/

// memoization
int minFair(int **arr, int **dp, int n, int m, int i, int j){
    if(i == n)
        return 0;
    if(j < 0 || j == m )
        return INT_MAX;
    if(dp[i][j] != -1)
        return dp[i][j];
    
    dp[i][j] = arr[i][j] + min( minFair(arr, dp, n, m, i+1, j-1), min(minFair(arr, dp, n, m, i+1, j), minFair(arr, dp, n, m, i+1, j+1)));
    
    return dp[i][j];
}

int main(){
    int n, m;
    cin >>n >> m;
    int **arr = new int*[n];
    int **dp = new int*[n];
	for(int i=0; i<n; i++){
        arr[i] = new int[m];
		dp[i] = new int[m];
	}
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> arr[i][j];
        	dp[i][j] = -1;
        }
	}
    
    int ans = INT_MAX;
    for(int i=0; i<m; i++){
        int temp = minFair(arr, dp, n, m, 0, i);
        ans = min(ans, temp);
    }
    cout << ans <<endl;
    
    return 0;
}


// Iterative DP
/*
int main(){
    int n, m;
    cin >>n >> m;
    int **arr = new int*[n];
    int **dp = new int*[n];
    
	for(int i=0; i<n; i++){
        arr[i] = new int[m];
		dp[i] = new int[m];
	}
    
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> arr[i][j];
    
    for(int i=0; i<m; i++){
        dp[n-1][i] = arr[n-1][i];
    }
    
    for(int i=n-2; i>= 0; i--){
        for(int j=0; j<m; j++){
            int option1 = dp[i+1][j];
            int option2 = INT_MAX;
            int option3 = INT_MAX;
            if(j > 0)
                option2 = dp[i+1][j-1];
            if(j+1 <m)
                option3 = dp[i+1][j+1];
            dp[i][j] = arr[i][j] + min(option1, min(option2, option3) );
        }
    }
    
    int ans = dp[0][0];
    for(int j=1; j<m; j++){
        ans = min(ans, dp[0][j]);
    }
    cout << ans <<endl;
    
    return 0;
}
*/
