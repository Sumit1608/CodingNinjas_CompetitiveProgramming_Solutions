#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

/*

Time comp =>  O(n log d)   d is the difference between the max and min distance possible

test case is
1
5
3 1 2 8 4 9

The logic here is that if a minimum maximum distcance of k is not poosible,  then for all x (> k) it will also
not poosible.  So, first find whether its possible for mid element or not,   if yeas,  then go in the right subarray
if not, then go to left part.

So, we can keep the cows at 1,2,8,4 and 9th position. Now we’ve to find the largest minimum distance between 2 cows.
It’s clear that minimum distance can be 0 (all cows in the same stall) or a[n-1] (2 cows at 1st and last position).
So binary search starts with l=0 and r=a[n-1] and we’ve to find the maximum distance. For that, we’ll just create a 
function(check) which returns true if that is the desired distance else false.
It’ll just check whether the difference between current stall and previous stall is at least x or not and if yes,
it’ll increase the temp(No of cows). If temp==c, it means we can store all the cows with the difference x(mid). So,
we return true, else false.
We’ll be doing the binary search for finding the best possible maximum difference.
*/

bool check(int cows, ll positions[], int n, ll distance){
	int count = 1;
	ll last_position = positions[0];
	
	for(int i=0; i<n; i++){
		if(positions[i] - last_position >= distance ){
			last_position  = positions[i];
			count ++;
		}
		if(count == cows){
			return true;
		}
	}
	return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,c;
		cin >> n>> c;
		
		ll positions[n];
		for(int i=0; i<n; i++){
			cin>>positions[i];
		}
		
		sort(positions, positions+n);
		ll start = 0;
		ll end = positions[n-1] - positions[0];
		
		ll ans = -1;
		
		while( start <= end){
			ll mid = (start + end)/2;
			
			if( check(c, positions, n, mid) ){
				ans = mid;
				start = mid+1;
			}
			else{
				end = mid-1;
			}
		}
		
		cout << ans << endl;
	}
}
