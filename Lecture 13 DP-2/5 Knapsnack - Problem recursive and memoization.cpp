#include<bits/stdc++.h>
using namespace std;

/*
Method 1: Recursion by Brute-Force algorithm OR Exhaustive Search.
Approach: A simple solution is to consider all subsets of items and calculate the total weight and value of all subsets. Consider the only subsets whose total weight is smaller than W. From all such subsets, pick the maximum value subset.
Optimal Sub-structure: To consider all subsets of items, there can be two cases for every item. 

Case 1: The item is included in the optimal subset.
Case 2: The item is not included in the optimal set.
Therefore, the maximum value that can be obtained from ‘n’ items is the max of the following two values. 

Maximum value obtained by n-1 items and W weight (excluding nth item).
Value of nth item plus maximum value obtained by n-1 items and W minus the weight of the nth item (including nth item)

Time Complexity: O(2^n). 
Auxiliary Space :O(1). 
*/

int knapSack(int W, int wt[], int val[], int n){
	// Base case
	if(n == 0 || W <= 0){
		return 0;
	}
	// If weight of the nth item is more than Knapsack capacity W, then
    // this item cannot be included in the optimal solution
	if(wt[n - 1] > W){
		return knapSack(W, wt, val, n-1);
	} 
	// Return the maximum of two cases:
    // (1) nth item not included
    // (2) nth item included
	else{
		return max( knapSack(W, wt, val, n-1), val[n-1] + knapSack(W-wt[n-1], wt, val, n-1));
	}
}





// Memoization 
//Time Complexity: O(N*W). 
//Auxiliary Space: O(N*W). 
int knapSackRec(int W, int wt[], int val[], int i, int** dp){
	if( i< 0){
		return 0;
	}
	if( dp[i][W] != -1){
		return dp[i][W];
	}
	
	if( wt[i] > W){
		dp[i][W] = knapSackRec(W, wt, val, i-1, dp);
	} else{
		dp[i][W] = max( knapSackRec(W, wt, val, i-1, dp), val[i] + knapSackRec(W-wt[i], wt, val, i-1, dp));
	}
	return dp[i][W];
}

int knapsackMem(int W, int wt[], int val[], int n){
    int** dp = new int*[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[W + 1];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < W + 1; j++)
            dp[i][j] = -1;
    
    return knapSackRec(W, wt, val, n - 1, dp);
}

int main(){
    int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = 3;
    cout << knapSack(W, wt, val, n) <<endl;
    cout << knapsackMem(W, wt, val, n) <<endl;
	return 0;
}
