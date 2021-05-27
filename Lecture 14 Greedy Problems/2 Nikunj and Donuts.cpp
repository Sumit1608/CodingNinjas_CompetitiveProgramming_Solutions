#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

// time comp => O(nlogn)
// we have to find the minimum of arr[i]*2^j  for i and j in [0, n-1]
// so, the best method for it would be to sort the array in descending order
// and then multiply the elements with 2^0, 2^1, 2^2,... so on, and add them 
//to get the minimum ans as possible
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    sort(arr, arr + n, greater<int>());
    
    ll ans = 0;
    for(int i=0; i<n; i++){
    	ll k = 1;
        ans += arr[i]*(k << i);
    }
    cout << ans <<endl;
	return 0;
}
