#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll kadane ( ll arr[], int n){
	ll current_sum = 0;
	ll best_sum = INT_MIN;
	
	for(int i =0; i<n; i++){
		current_sum += arr[i];
		if(best_sum < current_sum){
			best_sum = current_sum;
		}
		if(current_sum < 0){
			current_sum = 0;
		}
	}
	
	return best_sum;
}


int main(){
    int m,n;
    cin >>n >>m;
    int **arr = new int*[n];
    for(int i=0; i<n; i++){
        arr[i] = new int[m];
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >>arr[i][j];
        }
    }
    
    ll maxSum = INT_MIN;
    for(int left=0; left<m; left++){
        ll temp[n] = {0};
        
        for(int right = left; right<m; right++){
            for(int i=0; i<n; i++){
        	    temp[i] += arr[i][right];
    	    }
	        maxSum = max(maxSum, kadane(temp, n));
        }
    }
    
    cout <<maxSum <<endl;
    return 0;
}


/*
Using Kadane Algorithm
We can optimize the brute force with the help of the ‘Kadane algorithm’ for a 1-D array which is used to find the maximum subarray sum.  We will fix the left and right boundaries for a rectangle. We will then store the sum of elements of the matrix from ‘leftBoundary’ to ‘rightBoundary’, in an auxiliary array ‘temp’ of size ‘N’. We will then use the ‘Kadane algorithm’ to find the maximum subarray sum for ‘temp’.

The algorithm will be-

Initialize variable ‘maxSum’ to a minimum value.
We define a ‘temp’ array, whose size is the same as N.
For LEFT from 0 to the M, do:
Fill the ‘temp’ array with 0.
For RIGHT from LEFT to M - 1, do:
For each row i, do temp[i] =temp[i] + temp[i][RIGHT] for each 0 <= i < ROW
Assign sum = kadaneAlgorithm(temp, N)
if sum > maxSum, then assign maxSum = sum
Return ‘maxSum’.
The function kadaneAlgorithm has two parameters ARR and N and calculates the SUM as follows:

Initialize variable ‘sum’ to 0 and ‘maxSum’ to a minimum value.
We will iterate through the ARR. We will maintain the variable ‘sum’ denoting the maximum sum of prefix elements. Let the current index be ‘currIndex’.
For each iteration, we will-
Add ARR[currIndex] to sum.
Update maxSum if the value of sum becomes greater than maxSum.
If sum becomes negative, we will replace the value of the sum with 0.
The value stored in maxSum will be our answer.
Time Complexity
O(N * M * M), where N denotes the number of rows of the matrix and M denotes the number of columns of the matrix.

We will iterate over all left and right boundaries of the rectangle in O(M * M) time complexity. For each boundary, we are using the ‘Kadane Algorithm’ for finding out the maximum subarray sum in O(N) time complexity.  

Hence, overall time complexity will be O(N * M * M).

Space Complexity
O(N), where N denotes the number of rows of the matrix.

The space complexity due to the array/list ‘temp’ will be O(N).
*/


