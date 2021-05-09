#include <bits/stdc++.h>
using namespace std;

//time comp => O(n^2)
//DP[i] state represents the maximum happiness we can attain by ending our tour from city 1 to city i.
//Now, obviously dp[1], i.e the maximum happiness you can gain by starting your tour from city 1 and 
//ending it at city 1 itself is going to be the F1. This stands as our base case.
//Now, use an iterative style DP. Suppose I have to fill dp[i], then I will check for each 
// j ( i<j<n ), in which city ( i ) is choosen from i+1 to n so that if I end my tour at city i, 
//I will have the maximum magnitude of happiness.

//Now for each i iterating through i+1 to N, you will subsequently be solving dp[i],
// and if you focus you will find that the answer to the problem is nothing but dp[N].

double distance(double *x, double *y, int i, int j){
    double xDistance = x[i] - x[j];
    double yDistance = y[i] - y[j];
    double ans = sqrt( (xDistance*xDistance) + (yDistance * yDistance));
    return ans;
}

void maxHappiness(double *x, double *y, double *f, int n){
    double *dp = new double[n+1];
    for(int i=0; i<n; i++)
        dp[i] = -1e9;
    dp[0] = 0;
    
    for(int i=0; i<n; i++){
        dp[i] += f[i];
        for(int j=i+1; j<n; j++){
            dp[j] = max(dp[j], dp[i] - distance(x, y, i, j) );
        }
    }
    cout << fixed << setprecision(6) << dp[n-1] <<endl;
    
}

int main(){
    int n;
    cin >>n;
    
    double *x = new double[n];
    double *y = new double[n];
    double *f = new double[n];
    for(int i=0; i<n; i++){
        cin >> x[i] >> y[i] >> f[i];
    }
    
     maxHappiness(x, y, f, n);
}


