#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// time comp => O(n)
/*
If you write cost function for path i->j->k and compare it with the cost function for 
path i->k you can see that the former is better (costs less energy) if and only if 
either |A[j]| < |A[i]| or |A[j]| = |A[i]| with A[i]>0.
From this observation it is quite easy to see that the optimal path would be greedy 
jumping from 0 to first i such that |A[i]| < |A[0]| or A[i] = -A[0] (if A[0]>0) or 
directly to n-1 if there is no such i and then doing the same for i till we reach n - 1. 
Jumping greedily to n-1 solves the problem with O(N) complexity.
*/

ll calculate(ll *arr, ll i, ll j){
	return ( (j-i)*arr[i] + (j*j - i*i)*arr[i]*arr[i] );
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n;
    cin >> n;
    ll *arr = new ll[n];
    for(int i=0; i<n; i++)
        cin >> arr[i] ;
    
    ll curr =0;
    ll ans =0;
    
    while(curr < n-1){
    	ll next = curr+1;
    	while(next < n-1){
			if( (abs(arr[curr]) > abs(arr[next]) ) || (( abs(arr[curr]) == abs(arr[next]) )&& arr[curr] > 0) ){
				break;
			} else{
				next++;
			}
		}
		ans += calculate(arr, curr, next);
		curr = next;
	}
    
    cout << ans << endl;
    return 0;
}



