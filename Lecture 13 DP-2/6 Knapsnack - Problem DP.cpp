#include <cstring>
#include <iostream>
using namespace std;

//time comp => O(n*w)
//DP
int KnapSack(int *weight, int *value, int n, int maxWeight){
	int dp[n + 1][maxWeight + 1];
	for(int i =0; i<= n; i++){
		for(int j = 0; j<= maxWeight; j++){
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else{
				if(weight[i-1] > j)
					dp[i][j] = dp[i-1][j];
				else
					dp[i][j] = max(dp[i-1][j], value[i-1] + dp[i-1][j - weight[i-1]]);
			}
		}
	}
	return dp[n][maxWeight];
}

// Using space comp => O(maxWeight)
int knapsack(int* weight, int* value, int n, int maxWeight) {
	int *dp = new int[maxWeight + 1]();
    int *temp = new int[maxWeight + 1]();
    // for every row to fill, we need the result of the previous row
    // so, dp will store the result till (i-1)th row and temp will have the resutof ith row
    // then we store the result in dp
    for(int i=0; i<n; i++){
        for(int j=1; j<= maxWeight; j++){
            if(weight[i] > j){
                temp[j] = dp[j];
            } else{
                temp[j] = max(dp[j-weight[i]] + value[i], dp[j]);
            }
        }
        
        for(int j=1; j<= maxWeight; j++){
            dp[j] = temp[j];
        }
    }
    
    return dp[maxWeight];
}

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;
    cout << knapsack(wt, val, n, w) << "\n";
    cout << KnapSack(wt, val, n, w) << "\n";
    delete[] wt;
    delete[] val;
}
