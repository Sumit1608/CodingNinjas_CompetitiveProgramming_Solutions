#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

/*
In this problem, we are given a list of N numbers out of which K numbers are to be chosen
such that the unfairness sum is minimized.
Let us define D as the unfairness sum of chosen K numbers.

First, we claim that k such numbers can only be obtained if we sort the list and choose k 
contiguous numbers. This can easily be proven. Suppose we choose numbers X1, X2, X3,....Xr, Xr+1,....,XK.
All are in increasing order but not continuous in the sorted list, i.e. there exists a number 
p which lies between Xr and Xr+1. Now, if we include p and drop X1, our unfairness sum will 
decrease by an amount = ( |X1 - X2| + |X1 - X3| + .... + |X1 - XK| ) - ( |p - X2| + |p - X3| + .... + |p - XK| )
which is certainly positive. This shows that the solution will consist of k continuous elements of the sorted list.
Now there exists (N-K+1) such sets of elements. The problem can be redefined as to find the minimum of the D obtained from all these sets.

First, we sort the list in increasing order: X1, X2, X3,....XK,XK+1,....,XN. The next step is to find 
the value of D for the first K elements i.e. from X1 to XK. suppose we have calculated D for first i 
elements. When we include Xi+1, the value of D increases by ( |Xi+1 - X1| + |Xi+1 - X2| +....+ |Xi+1 - Xi| ), 
which in turn is equal to ( i*XK - (X1 + X2 + ....+Xi) ). We just need to store the sum of the current elements 
and repeat the step for i = 1 to k-1.

Now that we have the solution for X1 to XK, we want to calculate the same for X2 to XK+1. This can be done in O(1) time.
New unfairness sum = old unfairness sum + ( |XK+1 - X2| + |XK+1 - X3| + .... + |XK+1 - XK| ) - ( |X1 - X2| + |X1 - X3| + .... + |X1 - XK| ).
This can be written in the following form:
New unfairness sum = old unfairness sum + K.(XK - X1) - K.(X1 + X2 +....+XK) + ( X1 - XK)
At every point we just need to update the sum of the K elements, calculate the new unfairness sum and update the minimum value of the same.
*/

// time comp => O(nlogn)   coz of sorting

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,k;
    cin >> n >> k;
    ll *arr = new ll[n];
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    
    ll *sum = new ll[n];
    sum[0] = arr[0];
    //make this cumulative sum array because 0<=k <=10^5, so using two loops will give TLE.
    for(int i = 1; i < n; i++){
		sum[i] = sum[i-1] + arr[i];
	}
    
    //find the unfairness for first k elements 
    ll oldUnfairness = 0;
    for(int i=1; i<k; i++){
        oldUnfairness = oldUnfairness + i*arr[i] - sum[i-1];
    }
    
    ll minUnfairness = oldUnfairness;
    for(int i=k; i<n; i++){
        ll newUnfairness = oldUnfairness + (k-1)*(arr[i] + arr[i-k]) - 2*(sum[i-1] - sum[i-k]) ;        
        minUnfairness = min(minUnfairness, newUnfairness);
        oldUnfairness = newUnfairness;
    }

    cout << minUnfairness << endl;
    return 0;
    
    //another way
    /*
    ll minUnfairness = 0;
    int start = 0;
    int end = k-1;
    for(int a = 1; a <= end; a++){
        minUnfairness += a*arr[a]-sum[a-1];
    }

    ll currUnfairness = minUnfairness;
    start++; end++;
    while(end < n){
        currUnfairness += (end-start)*arr[end]-sum[end-1]+sum[start-1];
        currUnfairness -= sum[end-1]-sum[start-1]-(end-start)*arr[start-1];
        minUnfairness=min(minUnfairness, currUnfairness);
        start++;
        end++;
    }

    cout << minUnfairness << endl;
    */
}



