#include <bits/stdc++.h>
using namespace std;

//time comp => O(n^3)

/*
We are given an array A of length N. Let’s work with a function f(i, g)
which returns the number of increasing subsequences that end at index i (and begin at any index before that) 
which have gcd = g. We will compute this function for all relevant values of i and g, and at the end our 
answer will be \sum\limits_{i=1}^{n}f(i,1) 
 i.e.  submission of i=1 for i<n over f(i,1);

How do we recursively define our function f(i, g)?
Let there be some increasing subsequence S that ends at index j < i. We can only append A[i] to the end of 
S if A[j] < A[i], because we only want increasing subsequences. Let’s say this condition is satisfied, then S
 concatenated with A[i] will be an increasing subsequence that ends at index ii with gcdgcd value equal to gcd(gcd(S), A[i]).

Hence, the number of increasing subsequences that end at ii with gcd=g will be the total number of increasing subsequences
 that end at some j < ij<i such that A[i]>A[j]A[i]>A[j] and the gcdgcd of these subsequences and A[i] equal g.
The base case arises for each subsequence of length 1, i.e. the a single element of AA. For g=A[i], the value of f(i, g)
 is the above summation plus 1, for the single element itself is an increasing subsequence.
As the maximum value of A[i] is 100100, the dp table will be required of dimension N×100, and time complexity will be
 O(N^2*100)  Take a look at the pseudocode below

for i in [1..n]
    for g in [1..100]
        dp[i][g] = 0
    dp[i][a[i]] = 1

    for j in [1..i-1]
        if a[i]<=a[j]
            continue
        for k in [1..a[j]]
            g = gcd(a[i], k)
            dp[i][g] += dp[j][k]
*/

int mod = 1000000007;
typedef long long int ll;

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    ll** dp = new ll* [n];
	for (int i = 0; i < n; i++){
		dp[i] = new ll[101];
		for (int j = 0; j <= 100; j++)
			dp[i][j] = 0;
    }
    
    dp[0][arr[0]] = 1;
    ll sum = dp[0][1];
    for(int i = 1; i < n; i++){
        for(int j= i-1; j >= 0; j--){
            if(arr[i] > arr[j]){
                for(int g = 1; g <= 100; g++){
                	int new_gcd = __gcd(arr[i], g);
                    dp[i][new_gcd] =(dp[i][new_gcd]+ dp[j][g]) % mod;
                }
            }
        }
        dp[i][arr[i]]++;
        sum = (sum + dp[i][1]) % mod;
    }
    
    cout <<sum << endl;
    
    return 0;
}

