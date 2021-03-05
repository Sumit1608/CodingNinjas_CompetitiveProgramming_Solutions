#include<bits/stdc++.h>
using namespace std;

//Time comp => O(n)
//For ex, there are 5 shops having very long queue, now the person will
//come to window ith after t*n time where 0<=t<=n,   so w must find minimum t for
//every window, and thus we will be able to caclculate the window at which
//the person will buy ticket   .
//Expression =>    i + t*n >= arr[i],  so we can find t from here
//If (arr[i]-i)/n have 0 remainder then t remains as it is,  if non-zero remainder,
//then we increment that t.

int main(){
    int n;
    cin >>n;
    long long arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        arr[i] -= i;
        if(arr[i]<0){
            arr[i] = 0;
        }
    }
    long long ans = INT_MAX;
    int ansIndex = 0;
    for(int i=0; i<n; i++){
        long long smallans = arr[i]/n;
        if( arr[i]%n != 0){
            smallans++ ;
        }
        if(ans > smallans){
            ans = smallans;
            ansIndex = i+1;
        }
    }
    cout << ansIndex <<endl;
	return 0;
}

