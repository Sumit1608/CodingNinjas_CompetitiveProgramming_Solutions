#include<bits/stdc++.h>
using namespace std;

// time comp => O(n*sum)
/*
We will consider two cases. 
Consider the last element and now the required sum = target sum – value of ‘last’ element and number of elements = total elements – 1
Leave the ‘last’ element and now the required sum = target sum and number of elements = total elements – 1

The state DP[i][j] will be true if there exists a subset of elements from A[0….i] with sum value = ‘j’.
The approach for the problem is:
if (A[i-1] > j)
	DP[i][j] = DP[i-1][j]
else 
	DP[i][j] = DP[i-1][j] OR DP[i-1][j-A[i-1]]
This means that if current element has value greater than ‘current sum value’ we will copy the answer for previous cases
And if the current sum value is greater than the ‘ith’ element we will see if any of previous states have already experienced the 
sum=’j’ OR any previous states experienced a value ‘j – A[i]’ which will solve our purpose.
*/
bool isSubsetPresent(int *arr, int n, int sum){
    bool **dp = new bool*[n+1];
	for(int i=0; i<=n; i++){
		dp[i] = new bool[sum+1];
	}
	
	for(int i=0; i<=sum; i++){
		dp[0][i] = false;
	}
	for(int i=0; i<=n; i++){
		dp[i][0] = true;
	}
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=sum; j++){
			dp[i][j] = dp[i-1][j] ;
			if(j >= arr[i-1]){
				dp[i][j] = dp[i][j] || dp[i-1][j - arr[i-1]];
			}
		}
	}
	return dp[n][sum];
}

// optimizing space
// as we require (i-1)th row result to find ith row result
// so, we can only use two rows to get our required result
/*
bool subsetSum(int* val,int n,int sum){
	bool** dp = new bool*[2];
	for(int i=0;i<=1;i++){
		dp[i] = new bool[sum+1];
	}

	for(int i=0;i<=sum;i++){
		dp[0][i] = false;
	}
	dp[0][0] = true;

	int flag = 1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			dp[flag][j] = dp[flag^1][j];

			if(j>=val[i-1]){
				dp[flag][j] = dp[flag][j] || dp[flag^1][j-val[i-1]];
			}
		}
		// to toggle between the rows, we take XOR
		flag = flag ^ 1;
	}
	bool ans = dp[flag^1][sum];
	// delete dp array
	return ans;
}
*/

int main(){
	int n, sum;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> sum;
    if (isSubsetPresent(arr, n, sum))
        cout << "Yes";
    else
        cout << "No";

    delete[] arr;
	return 0;
}
