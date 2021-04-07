#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;


//Time comp => O(n)
// A balanced binary tree is one in which for every node, the difference between heights of left and right subtree is not more than 1.
//Height of tree, h = 1 + max(left height, right height)
//Since the difference between the heights of left and right subtree is not more than one, possible heights of left and right part can be one of the following:
//1. (h-1), (h-2)      2. (h-2), (h-1)       3. (h-1), (h-1)
//count(h) = count(h-1)*count(h-2) + count(h-2)*count(h-1) + count(h-1)*count(h-1) = count(h-1)*( 2*count(h-2) + count(h-1))

int balancedBTs(int h) {
    long long int dp[h + 1];
    //base cases
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= h; i++) {
        dp[i] = (dp[i - 1] * ((2 * dp [i - 2])%mod + dp[i - 1])%mod) % mod;
    }
    return dp[h];

}

int main() {
    int n;
    cin >> n;
    cout << balancedBTs(n);
}
