#include<bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;

//time comp => O(101 * 101 *2*t)
//int32_t main(){
int main(){
	//fill all the outputs with the numbers ending with 0 and 1 separately so that answer can be directly accessed
    int dp[101][101][2];
    for (int i = 0; i <= 100; i++)
        for (int j = 0; j <= 100; j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = 0;
        
    dp[1][0][0] = 1;
    dp[1][0][1] = 1;
    
    //i denotes the number of bits
    for (int i = 2; i <= 100; i++){
        // j denotes the adjacent bit count of length i
        for (int j = 0; j <= i - 1; j++){
            // adding 0 at end of the (n-1) number of bits
            dp[i][j][0] = dp[i - 1][j][0];
            dp[i][j][0] += dp[i - 1][j][1];
            dp[i][j][0] %= mod;

            // adding 1 at the end of (n-1) number of bits
            if (j - 1 >= 0)
                dp[i][j][1] = dp[i - 1][j - 1][1];
            dp[i][j][1] += dp[i - 1][j][0];
            dp[i][j][1] %= mod;
        }
    }
	
    int t;
    cin >>t;
    while(t--){
        int num, n, k;
        cin >> num >> n>> k;
        
        cout <<num << " " << (dp[n][k][0] + dp[n][k][1]) % mod <<endl;
    }

    return 0;
}

/*
Let f(n, k, 0) represent the number of strings of length n, k bits set starting with 0.
Let f(n, k, 1) represent the number of strings of length n, k bits set starting with 1.

Let T(n, k) represent the total number of strings of length n with k bits set.

T(n, k) = f(n, k, 0) + f(n, k, 1)

Case 1: First digit is 0. In that case, the second digit may either be 0 or 1. In either case, it doesn't impact bit count

f(n, k, ZERO FIRST) = f(n - 1, k, ZERO FIRST) + f(n - 1, k, ONE FIRST) = T(n - 1, k)

Case 2: First digit is 1. The second digit may be 0 or 1. The former doesn't affect the bit count but the latter increases the bit count by 1.

f(n, k, ONE FIRST) = f(n - 1, k, ZERO FIRST) + f(n - 1, k - 1, ONE FIRST) = T(n - 2, k) + f(n - 1, k - 1, ONE FIRST)

Base Case - If there is one bit, the number of set bits is always 0, regardless of what the bit is.

            f(1, 0, ONE FIRST) = f(1, 0, ZERO FIRST) = 1
            f(1, 1, ONE FIRST) = f(1, 1, ZERO FIRST) = 0

Also, f(n, 0, ZERO FIRST) = f(n - 1, 0, ZERO FIRST) + f(n - 1, 0, ONE FIRST)
      f(n, 0, ONE FIRST)  = f(n - 1, 0, ZERO FIRST)

Here we do not count the string of length starting with 11 because the bit count becomes 1.

*/

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long int ll;

// //recursive approach
// int recur(int n, int i, int k, int prev){
//     if(i == n){
//         if(k == 0)
//             return 1;
//         else
//             return 0;
//     }

//     if(prev == 1){
//         return (recur(n, i+1, k-1, 1) + recur(n, i+1, k, 0) );
//     } else{
//         return (recur(n, i+1, k, 1) + recur(n, i+1, k, 0) );
//     }
// }

// int main(){
//     int t;
//     cin >>t;
//     while(t--){
//         int num, n, k;
//         cin >> num >> n>> k;
        
//         int count = 0;
//         //00
//         count += 2*recur(n,2, k, 0 );
//         //10
//         // count += recur(n,2, k, 0 );
//         //01
//         count += recur(n,2, k, 1 );
//         //11
//         count += recur(n,2, k-1, 1 );
        
//         cout <<num << " " << count <<endl;
//     }
// }

