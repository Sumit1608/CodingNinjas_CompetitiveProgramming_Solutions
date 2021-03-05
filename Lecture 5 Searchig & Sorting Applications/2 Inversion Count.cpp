#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

/*
Enhance Merge Sort
Time comp => O(nlogn)

Approach: 
Suppose the number of inversions in the left half and right half of the array (let be inv1 and inv2),
what kinds of inversions are not accounted for in Inv1 + Inv2? The answer is – the inversions that need
to be counted during the merge step. Therefore, to get a number of inversions, that needs to be added a
number of inversions in the left subarray, right subarray, and merge().
Algorithm: 
1. The idea is similar to merge sort, divide the array into two equal or almost equal halves in each step
until the base case is reached.
2. Create a function merge that counts the number of inversions when two halves of the array are merged,
create two indices i and j, i is the index for first half and j is an index of the second half. if a[i] is
greater than a[j], then there are (mid – i) inversions. because left and right subarrays are sorted, so all
the remaining elements in left-subarray (a[i+1], a[i+2] … a[mid]) will be greater than a[j].
3. Create a recursive function to divide the array into halves and find the answer by summing the number of
inversions is the first half, number of inversion in the second half and the number of inversions by merging
the two.
4. The base case of recursion is when there is only one element in the given half.
5. Print the answer
*/

ll merge(int a[], int left, int mid, int right){
	int i=left, j = mid, k = 0;
	int temp[right - left +1];
	
	ll count = 0;
	while(i<mid && j<= right){
		if(a[i] <= a[j]){
			temp[k++] =  a[i++];
		}
		else{
			temp[k++] = a[j++];
			count = count + (mid - i);
		}
	}
	
	while(i < mid){
		temp[k++] = a[i++];
	}
	while(j <= right){
		temp[k++] = a[j++];
	}
	
	for(i = left, k=0; i<= right; i++,k++){
		a[i] = temp[k];
	}
	return count ;
}

ll merge_sort(int a[], int left, int right){
	if(right > left){
		int mid = (right+left)/2;
		ll  countLeft = merge_sort(a, left, mid);
		ll rightCount = merge_sort(a, mid+1, right);
		ll myCount = merge(a, left, mid+1, right);
		return countLeft + rightCount + myCount;
	}
	return 0;
}

ll solve(int a[], int n){
	ll ans = merge_sort(a, 0, n-1);
	return ans;
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	cout << solve(arr, n) << endl;
}




/*
Simple Method 
Time comp => O(n^2)

Approach :Traverse through the array and for every index find the number of smaller elements on its
right side of the array. This can be done using a nested loop. Sum up the counts for all index in the
array and print the sum.

Algorithm : 
1. Traverse through the array from start to end
2. For every element find the count of elements smaller than the current number upto that index using another loop.
3. Sum up the count of inversion for every index.
4. Print the count of inversions.


int inversion(int arr[], int n){
	int count =0;
	for(int i=0; i<n-1; i++){
		for(int j=1; j<n; j++){
			if(arr[i] > arr[j]){
				count ++;
			}
		}
	}
	return count;
}

int main(){
	int n;
	cin >> n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	
	cout << inversion(arr, n) << endl;
}

*/
