#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int mod = 1000000007;

//time comp => O(n^2)
//For all possible values of i, consider i as root, then [1….i-1] numbers 
//will fall in the left subtree and [i+1….n] numbers will fall in the right
// subtree. So, add (i-1)*(n-i) to the answer. The summation of the products 
//will be the answer to the number of unique BST.
int countBST( int n){
    long long dp[n+1] = {0};
    //base case
    dp[0] = 1;
    dp[1] = 1;
    
    // fill the dp table in top-down approach.
    for(int i=2; i<= n; i++){
        for (int j = 1; j <= i; j++) {
            // n-i in right * i-1 in left
            int temp = (dp[i - j] * dp[j - 1])%mod;
            dp[i] = (dp[i] +temp)%mod;
        }
    }
    return dp[n];
}

int main(){
	int n ;
	cin>>n;
	cout<<countBST(n);
	return 0;
}

