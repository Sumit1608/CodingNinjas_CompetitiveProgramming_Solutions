#include <iostream>
using namespace std;

//Time Complexity: O(m*n) where m is number of rows and n is number of columns in the given matrix.
//Auxiliary Space: O(m*n) where m is number of rows and n is number of columns in the given matrix.
//Algorithm: Let the given binary matrix be M[R][C]. The idea of the algorithm is to construct an 
//auxiliary size matrix S[][] in which each entry S[i][j] represents size of the square sub-matrix with 
//all 0s including M[i][j] where M[i][j] is the rightmost and bottommost entry in sub-matrix.
//
//1) Construct a sum matrix S[R][C] for the given M[R][C].
//     a)    Copy first row and first columns as it is from M[][] to S[][]
//     b)    For other entries, use following expressions to construct S[][]
//         If M[i][j] is 0 then
//            S[i][j] = min(S[i][j-1], S[i-1][j], S[i-1][j-1]) + 1
//         Else /*If M[i][j] is 1*/
//            S[i][j] = 0
//2) Find the maximum entry in S[R][C]
//3) Using the value and coordinates of maximum entry in S[i], print 
//   sub-matrix of M[][]

int findMaxSquareWithAllZeros(int **arr, int n, int m){
    int **dp = new int*[n];
    int maxElements = 0;
    for(int i=0; i<n; i++){
        dp[i] = new int[m];
    }
    //filling the first row
    for(int i=0; i<m; i++){
        if(arr[0][i] == 0)
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
        maxElements = max(maxElements, dp[0][i]);
    }
    //filling the first column
    for(int i=0; i<n; i++){
        if(arr[i][0] == 0)
            dp[i][0] = 1;
        else
            dp[i][0] = 0;
        maxElements = max(maxElements, dp[i][0]);
    }
    
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(arr[i][j] == 0){
                if( dp[i-1][j] > 0 && dp[i][j-1] > 0 && dp[i-1][j-1] > 0 )
                    dp[i][j] = 1 + min(dp[i-1][j] , min(dp[i-1][j-1], dp[i][j-1] ) );
                else
                    dp[i][j] = 1;
                maxElements = max(maxElements, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    
    return maxElements;
}

int main(){
	int **arr, n, m, i, j;
	cin >> n >> m;
	arr = new int *[n];
	
	for (i = 0; i < n; i++)
		arr[i] = new int[m];

	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			cin >> arr[i][j];

	cout << findMaxSquareWithAllZeros(arr, n, m) << endl;
	delete[] arr;
	return 0;
}
