#include <iostream>
#include <stdio.h>
using namespace std;

//time comp=> O(n)

int getMin(int *arr, int n){
    int dp[n] ={0};
    dp[0] = 1;
	
	// first fill the array from starting,  if the numbers are in increasing order
	//then they will be filled according to the increasing sequences
    for(int i=1; i<n; i++){
        if(arr[i] > arr[i-1]){
            dp[i] = dp[i-1]+1;
        } else{
            dp[i] = 1;
        }
    }
    //now fill from end so that dp also get filled according to decreasing sequence
	for(int i=n-2; i>=0; i--){
        if(arr[i+1] < arr[i] && dp[i] <= dp[i+1]){
            dp[i] = dp[i+1]+1;
        }
    }

    int sum =0;
    for(int i=0; i<n; i++){
        sum += dp[i];
    }
    return sum;
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << getMin(arr, n);
    delete[] arr;
}
