#include<bits/stdc++.h>
using namespace std;

//time comp => O(nlogn)
// sort the array and then find the minimum consecutive difference of the elements
int minAbsoluteDiff(int arr[], int n) {
    sort(arr, arr + n);
    int ans = INT_MAX;
    for(int i = 1; i < n; i++)
        ans = min(ans, arr[i] - arr[i-1]);
    return ans;
}

int main() {
	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	cout<< minAbsoluteDiff(input,size) << endl;
	return 0;
}

