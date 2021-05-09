#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

//Time comp => O(n^2)

//Input  : arr[] = {3, 10, 2, 11}
//LIS[] = {1, 1, 1, 1} (initially)

//Iteration-wise simulation : 
//arr[2] > arr[1] {LIS[2] = max(LIS [2], LIS[1]+1)=2}
//arr[3] < arr[1] {No change}
//arr[3] < arr[2] {No change}
//arr[4] > arr[1] {LIS[4] = max(LIS [4], LIS[1]+1)=2}
//arr[4] > arr[2] {LIS[4] = max(LIS [4], LIS[2]+1)=3}
//arr[4] > arr[3] {LIS[4] = max(LIS [4], LIS[3]+1)=3}

int lis(int arr[], int n){
	int temp[n];
	temp[0] = 1;
	for(int i=1; i<n; i++){
		temp[i] = 1;
		for(int j=i-1; j>=0; j--){
			if(arr[j] > arr[i]){
				continue;
			}
			int possibleAns = temp[j] +1;
			if(possibleAns > temp[i]){
				temp[i] = possibleAns;
			}
		}
	}
	
	int ans =0;
	for(int i=0; i<n; i++){
		ans = max(ans, temp[i]);
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin >>arr[i];
	}
	
	int ans = lis(arr, n);
	cout << ans <<endl;
}
