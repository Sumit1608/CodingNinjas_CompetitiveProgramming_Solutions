#include <bits/stdc++.h>
using namespace std;

//time comp => O(k*n)   using 3d DP
/*
#include <bits/stdc++.h>
using namespace std;

int solve(int *arr, int n, int k, int ongoing_transaction, int ***dp){
    // if there are no elements in the aray or we can't make more transactions, return 0
	if(n == 0 || k== 0)
        return 0;
    // check for the recurrence of the recursive call
    if( dp[n][k][ongoing_transaction] != -1)
        return  dp[n][k][ongoing_transaction];
    
    // don't make any buy/sell call on the 0th element
    int ans1 = solve(arr+1, n-1, k, ongoing_transaction, dp);
    int ans2 = 0;
    // either buy or sell the 0th element according to the ongoing_transaction
    if(ongoing_transaction == 1){
    	// sell the ith element
        ans2 = arr[0] + solve(arr+1, n-1, k-1, 0, dp);
    } 
    else {
    	// buy the ith element if we are allowed to make more transaction
        if(k >0)
	        ans2 = solve(arr+1, n-1, k, 1, dp) - arr[0];
    }
    
    dp[n][k][ongoing_transaction] = max(ans1, ans2);
	return dp[n][k][ongoing_transaction];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int k, n;
        cin >> k >> n;
        int *arr = new int[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        
        int ***dp=new int**[n+1];
		for(int i = 0; i <= n; i++){
			dp[i] = new int *[k+1];
			for(int j = 0; j <= k; j++){
				dp[i][j] = new int [2];
				for(int h = 0; h < 2; h++){
					dp[i][j][h] = -1;
				}
			}
		}
        cout << solve(arr, n, k, 0, dp) << endl;
        
		for(int i=0; i<n+1; i++){
			for(int j=0; j<k+1; j++)
				delete[]dp[i][j];
			delete[]dp[i];
        }
        
		delete[]dp;    
    }
    return 0;
}
*/


//time comp => O(k*n*n)
/*
Let profit[t][j] represent maximum profit using at most t transactions up to day i (including day i).
Then the relation is:
profit[t][i] = max(profit[t][i-1], max(price[i] � price[j] + profit[t-1][j]))   
for all j in range [0, i-1]

profit[t][j] will be maximum of :-
1. profit[t][i-1] which represents not doing any transaction on the ith day.
2. Maximum profit gained by selling on ith day. In order to sell shares on ith day, we need to 
purchase it on any one of [0,i-1] days. If we buy shares on jth day and sell it on ith day, max profit 
will be price[i] � price[j] + profit[t-1][j] where j varies from 0 to i-1. Here profit[t-1][j] 
is best we could have done with one less transaction till jth day.
*/
int solve(int *arr, int n, int k){
    int dp[k+1][n+1];
    
    for(int i=0; i<=k; i++)
        dp[i][0] = 0;
    for(int i=0; i<=n; i++)
        dp[0][i] = 0;
    
    for(int i=1; i<=k; i++){
        for(int j=1; j<n; j++){
            int maxTillNow =0;
            for(int h=0; h<j; h++){
                maxTillNow = max(maxTillNow, arr[j] - arr[h] + dp[i-1][h]);
            }
            dp[i][j] = max(maxTillNow, dp[i][j-1]);
        }
    }
    
    return dp[k][n-1];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int k, n;
        cin >> k >> n;
        int *arr = new int[n];
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        
        cout << solve(arr, n, k) << endl;
        
    }
    return 0;
}

