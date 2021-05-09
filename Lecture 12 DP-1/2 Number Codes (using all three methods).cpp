#include<bits/stdc++.h>
using namespace std;

//Time comp=> O(2^n)
// Let code be =>  1243
//Now, diff types of code may be =>  1 2 4 3,  12 4 3, 1 24 3=> abdc, ldc, axc
int num_codes(int *n, int size){
	if(size <=1){
		return 1;
	}
	
	int output = num_codes(n, size-1);
	if(n[size -2]*10 + n[size-1] <= 26){
		output += num_codes(n, size-2);
	}
	return output;
}

//Memoization
int num_codes2(int *n, int size, int *temp){
	if(size <=1){
		return 1;
	}
	if(temp[size-1] > 0){
		return temp[size];
	}
	
	int output = num_codes(n, size-1);
	if(n[size -2]*10 + n[size-1] <= 26){
		output += num_codes(n, size-2);
	}
	temp[size] = output;
	return output;
}

//DP   arr[i] denotes the answer for starting i elements in the array
int num_codesDP(int *input, int size){
	int a[size+1];
	a[0]=1;
	a[1]=1;
	for(int i=2; i<=size; i++){
		a[i] = a[i-1];
		if(input[i-2]*10 + input[i-1] < 26){
			a[i] += a[i-2];
		}
	}
	return a[size];
}

int main(){
	int n;
	cin>>n;
	int arr[n], temp[n];
	for(int i=0; i<n; i++){
		cin >>arr[i];
		temp[i] =0;
	}
	cout << num_codes(arr, n) <<endl;
	cout << num_codes2(arr, n, temp) <<endl;
	cout << num_codesDP(arr, n) <<endl;
}
