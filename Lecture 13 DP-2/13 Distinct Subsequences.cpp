#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
int const mod = 1000000007;

// time comp => O(n)
/*
Let countSub(n) be count of subsequences of  first n characters in input string. We can
recursively write it as below. 

countSub(n) = 2*Count(n-1) - Repetition

If current character, i.e., str[n-1] of str has not appeared before, then 
   Repetition = 0

Else:
   Repetition  =  Count(m)
   Here m is index of previous occurrence of current character. We basically remove all
   counts ending with previous occurrence of current character.
*/
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.length();
        
        int *lastIndex = new int[26];
        for(int i=0; i<26; i++){
            lastIndex[i] = -1;
        }
        
        ll *dp = new ll[n+1];
        // Empty substring has only one subsequence
        dp[0] = 1;
        for(int i=1; i<=n; i++){
            int index = lastIndex[ s[i-1] - 'A' ];
            if(index == -1){
                dp[i] = (2*dp[i-1])%mod;
            } else{
            	// 2*dp[i-1] - dp[index] can be negative, so add mod 
                // If current character has appeared before, then remove all subsequences ending with previous occurrence.
				dp[i] = (2*dp[i-1] - dp[index] + mod) %mod;
            }
            // Mark occurrence of current character
            lastIndex[ s[i-1] - 'A' ] = i-1;
        }
        
        cout << dp[n] <<endl;
        delete lastIndex;
        delete dp;
    }
    return 0;
}


