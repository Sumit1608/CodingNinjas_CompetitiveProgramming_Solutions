#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

//Time comp => (O(log n) )^2
//To find the minimum k, we first check on the mid value, if it satisfies, that means all value greater than
//mid will also satisfy, so to find min k,  we find on left side of mid
// If mid value doesn't satisfy , then we check on right of mid

//To check whether a number k satisfy the condition or not,  we calculate it's sum and check whether at last
// 2 times of the sum is greater than or equal to n or not
bool check(ll n, ll k){
    ll total = n;
    ll sum= 0;
    while( n >= k){
        sum += k;
        n -= k;
        n -= n/10;
    }
    sum += n;
    if( 2*sum >= total){
        return true;
    } 
    return false;
}

int main(){
    ll n;
    cin>>n;
    ll start =1;
    ll end = n;
    ll ans =0;
    while(start <= end){
        ll mid = (start + end)/2;
        if( check(n, mid) ){
            end = mid -1;
            ans = mid;
        } else{
            start = mid+1;
        }
    }
    cout << ans << endl;
	return 0;
}

