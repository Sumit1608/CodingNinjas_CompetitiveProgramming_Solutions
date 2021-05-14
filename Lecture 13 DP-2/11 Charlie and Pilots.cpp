#include <bits/stdc++.h>
using namespace std;

//time comp => O(n*n/2) = O(n^2)
int solve(int *cap, int *ass, int n, int x, int **dp){
    // if there are no pilots left
    if(n == 0)
        return 0;
    
    if(dp[n][x] != -1)
        return dp[n][x];
    
    int ans;
    // if the number of assistance and number of captains ae equal, then we have to make the 
    // next pilot as assistance as age of captian > age of assistance
    if(x == 0){
        ans = ass[0] + solve(cap+1, ass+1, n-1, x+1, dp);
    }
    // if the number of assistances have been n/2,  so make the remaining pilots as age of captian > age of assistance
    else if(x == n){
        ans = cap[0] + solve(cap+1, ass+1, n-1, x-1, dp);
    }
    else{
        // we can either make this pilot as captian or as assitance
        int ans1 = ass[0] + solve(cap+1, ass+1, n-1, x+1, dp);
        int ans2 = cap[0] + solve(cap+1, ass+1, n-1, x-1, dp);
        ans = min(ans1, ans2);
    }
    
    dp[n][x] = ans;
    return ans;
}

int main(){
    int n;
    cin >> n;
    int *cap = new int[n];
    int *ass = new int[n];
    for(int i=0; i<n; i++)
        cin >> cap[i] >> ass[i];
    
    // let x be the difference between number of assistance and number of captains
    // 0 <= x <= n/2
    int x =0;
    
    int **dp = new int*[n+1];
    for(int i=0; i<=n; i++){
        dp[i] = new int[n/2 + 1];
        for(int j=0; j<= n/2; j++)
            dp[i][j] = -1;
    }

    cout << solve(cap, ass, n, x, dp) << endl;
    
    return 0;
}

