#include<bits/stdc++.h>
using namespace std;

//Time comp => O(n logn) due to sorting
//Simply sort the array,  use two pointer to get the count off variation pairs
//For example, input =>   n=5  k=3
//arr = 7 2 9 4 0
//Sorted array =>  0 2 4 7 9
//Now,  i =0, for j= 2,   all the numbers from 4 to 9 will make a pair,  so we 
//add (n - j)  then increment i and check for remaining number until j becomes n.

long variationPairs(int arr[], int n, int k){
	sort(arr, arr+n);
	int i=0, j=1;
	long count = 0;
	while(j<n){
		if( (arr[j] - arr[i]) >= k){
			count += (n-j);
			i++;
		} else{
			j++;
		}
	}
	return count;
}

int main(){
	int n, k;
	cin>>n >> k;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}
	long count = variationPairs(arr, n, k);
	cout << count << endl;
	return 0;
}
