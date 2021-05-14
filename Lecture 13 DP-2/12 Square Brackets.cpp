#include <bits/stdc++.h>
using namespace std;

// memoization
// time comp => O(n^2)
int solve(int total, int opening, int closing, bool *arr, int **dp){
	// if the opening or closing brackets are greater than n, then return 0
    if(opening > total || closing > total)
        return 0;
    // if opening and closing brackets are equal to tatal that means we have completed a sequence
    if(opening == total && closing == total)
        return 1;
    if(dp[opening][closing] != -1)
        return dp[opening][closing];
    
    int ans;
    // if opening and closing brackets are equal, that means we should start the sequence from opening bracket
    // or if it is said to take opening bracket at ith position
    if(opening == closing || arr[opening + closing] == true)
        ans = solve(total, opening + 1, closing, arr, dp);
    // if opening brackets are equal to n, then place closing brackets to amke a perfect sequence
    else if(opening == total)
        ans = solve(total, opening , closing + 1, arr, dp);
    // we can take ith element as opening/closing bracket
    else{
        ans = solve(total, opening + 1, closing, arr, dp) + solve(total, opening, closing + 1, arr, dp);
    }
    dp[opening][closing] = ans;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        bool *arr = new bool[2*n+1];
        for(int i = 0; i <= 2*n; i++)
             arr[i] = false;
        
        for(int i=0; i<k; i++){
            int q;
            cin >> q;
            arr[q-1] = true;
        }
        
        int **dp = new int*[n+1];
        for(int i = 0; i <= n; i++){
             dp[i] = new int[n+1];
            for(int j=0; j<= n; j++){
                dp[i][j] = -1;
            }
        }
       
        cout << solve(n, 0, 0, arr, dp) << endl;  
    }
    return 0;
}

// recursive solution
// int solve(int total, int opening, int closing, bool *arr){
//     if(opening > total || closing > total)
//         return 0;
//     else if(opening == total && closing == total)
//         return 1;
//     else if(opening == closing || arr[opening + closing] == true)
//         return solve(total, opening + 1, closing, arr);
//     else if(opening == total)
//         return solve(total, opening , closing + 1, arr);
//     else{
//         return solve(total, opening + 1, closing, arr) + solve(total, opening, closing + 1, arr);
//     }
// }
