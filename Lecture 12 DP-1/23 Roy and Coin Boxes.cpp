#include <bits/stdc++.h>
using namespace std;

//time comp => O(n)
int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >>n >>m;
    
// start counts for how many days we start adding coins from this box and end counts for how many days
// we stop adding coins at this box. For a day where we start from L to R, we increment start[L] by 1 and increment end[R] by 1
    int *start = new int[n+1]();
    int *end = new int[n+1]();
    //dp will count the number of coins we get for coins 1<= i <= n
    int *dp = new int[n+1]();
    
    for(int i=0; i<m; i++){
        int a, b;
        cin >>a >>b;
        start[a]++;
        end[b]++;
    }
    
    for(int i=1; i<=n; i++){
        dp[i] = start[i] + dp[i-1] - end[i-1];
    }
    
    // feq will keep the count for number of coins that are present exactly once, twice, ...
    int *freq = new int[n+1]();
    for(int i=0; i<=n; i++){
        freq[ dp[i] ]++;
    }
    //now, freq will store the number of atleast i coins at ith poistion
    for(int i=n-1; i>=0; i--){
        freq[i] += freq[i+1];
    }
    
    int q;
    cin >>q;
    for(int i=0; i<q; i++){
        int query;
        cin >>query;
	    cout << freq[query] <<endl;
    }
}

/*
EXPLANATION:
Given N boxes, you are given that each day Roy adds one coin each to every box in the range [L,R]. Now, at the end of M days, he checks how many boxes have atleast X coins for multiple values of X.

The trivial solution that comes to mind is to create an array of size N and for each update [L,R], update 1 to each array index within this range. Then at the end, for each X, count by traversing the whole array, the number of boxes with this many or more number of coins.

One can easily figure out from the constraints that this solution is too slow to pass.

Observation 1: If we can keep track of how many days a box was between the starting box and the end box, then the total number of coins at the end is equal to this number. This is so because each day exactly one coin is added to a box which comes in between the starting and ending box.

Given this observation, now we have to come up with a way to count the total number of days a box was filled.

Observation 2: At a given day when Roy adds coins to boxes, he adds them to all the boxes within two points.

We are given the information that for each day from which box adding coins to the boxes was started and till which box the coins were added. Using this, for a particular box, we can count on how many days we start at this box and for how many days we end at the box.

This can be done quite simply by keeping two arrays (start and end), each of size N. start counts for how many days we start adding coins from this box and end counts for how many days we stop adding coins at this box. For a day where we start from L to R, we increment start[L] by 1 and increment end[R] by 1. For a single day, this can be done in O(1) time.

Finding the total number of coins at the end for each box:
Consider box 1, if we know that this box was opening box for ks1 days, then the total number of coins in this box can only be ks1 (because each day a coin was added to this box).
Consider box 2, we know that box 1 was starting box for ks1 days, we would add a coin to box 2, for each day where we start from box 2 itself (say ks2) and for those days where we start from box 1 but don’t stop at box 1. Those days will be exactly ks1 - ke1, where ke1 is the number of days box 1 was the final box of adding coins. Hence, the total number of coins in box 2 will be ks1 + ks2 - ke1 .
Now, for box 3, we can see that the total number of coins will be ks1 + ks2 + ks3 - ke1 - ke2. This follows for other boxes as well.

To compute the value for each of box, we can keep a running count of sum of all start values before that box minus the sum of all ending values before that box. Adding the starting value for that box itself to this sum gives the total number of coins in that box.

This solution will give us the total number of coins in a box in O(N) time.

Note that the total number of coins in a box can never be more than M. We keep an array of size M and using the above computation of finding total number of coins in a box, we populate how many boxes there are with i coins at the end for each i.

Observation 3: If a box is counted when we were counting for boxes with X or more coins, it will also be counted when we would count boxes with X-i or more coins, for positive values of i.

This observation helps us computing how many boxes have atleast X coins. We already know the count of boxes with exactly i number of coins for each i. This small last step is left for the reader to solve.

*/

