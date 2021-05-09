#include <bits/stdc++.h>
using namespace std;

//time comp => O(n)
int minCount(int n){
	int dp[n+1];
	//base case
    dp[0]=0;
    dp[1]=1;
    
    // getMinSquares rest of the table using recursive formula
    for(int i=2; i<=n; i++){
        int j=1;
        // max value is i as i can always be represented as 1*1 + 1*1 + ...
        dp[i] = i;
        while(j*j <= i){
        	// Go through all smaller numbers to recursively find minimum
            dp[i] = min(dp[i], 1+ dp[i - j*j]);
            j++;
        }
    }
    return dp[n];
}

int main(){
	int n;
	cin >> n;
	cout << minCount(n);
}
