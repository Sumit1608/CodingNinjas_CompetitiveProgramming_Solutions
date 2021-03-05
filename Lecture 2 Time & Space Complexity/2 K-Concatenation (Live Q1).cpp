#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll kadane ( int *arr, int n){
	ll current_sum = 0;
	ll max_so_far = INT_MIN;
	
	for(int i =0; i<n; i++){
		current_sum += arr[i];
		if(max_so_far < current_sum){
			max_so_far = current_sum;
		}
		if(current_sum<0){
			current_sum = 0;
		}
	}
	
	return max_so_far;
}

ll maxSubarraySum(int *arr, int n, int k){
	ll kadanes_sum = kadane(arr, n);
	if(k == 1){
		return kadanes_sum;
	}
	
	ll curr_prefix_sum = 0, curr_suffix_sum = 0;
	ll max_prefix_sum = INT_MIN, max_suffix_sum = INT_MIN;
	//Calculating max prefix and suffix sum
	for(int i=0; i<n; i++){
		curr_prefix_sum = curr_prefix_sum + arr[i];
		max_prefix_sum = max(max_prefix_sum, curr_prefix_sum);
	}
	for(int i = n-1; i>=0; i--){
		curr_suffix_sum = curr_suffix_sum + arr[i];
		max_suffix_sum = max( max_suffix_sum, curr_suffix_sum);
	}
	
	ll totalSum = 0;
	for(int i =0; i<n; i++){
		totalSum = totalSum + arr[i];
	}
	
	ll ans;
	if(totalSum < 0){
		ans = max( max_suffix_sum + max_prefix_sum, kadanes_sum);
	}
	else{
		ans = max( max_suffix_sum + max_prefix_sum + (totalSum*(k-2)), kadanes_sum);
	}
	return ans;
}

int main(){
	int t;
	cin>>t;
	
	while(t--){
		int n,k;
		cin>>n>>k;
		int *arr = new int[n];
		for(int i =0; i <n ; i++){
			cin>>arr[i];
		}
		cout << maxSubarraySum(arr, n, k) << endl;
	}
	return 0;
}


/*

Your problem is to find the maximum sub array of B. Maximum SubArray of an array A is a
continuous SubArray within the array A that has the largest Sum.
For e.g.. In a array having elements {-25 , 20, -3, -16, -23, 18, 20, -7, 12, -5, -22}
(Index starts with 0) the Maximum SubArray is from index 5 to index 8 which has a sum of 43.
No other continuous SubArray within A would have sum which exceeds 43.
The best method for finding Maximum SubArray is [Kadanae's algorithm][1].

Okay now let's jump into the problem. Here you have to find the Maximum SubArray for an
array B which is a k-times repetitive array of A. For e.g.. if A is {3, 2, -1} and K is 3
then B will be {3, 2, -1, 3, 2, -1, 3, 2, -1}. 

First method: 
    You can create a  array B using A and you can deploy Kadanae's algorithm on it to find
	the maximum SubArray. But it's not a good solution. Array A can have upto 10^5 elements
	and K can also have value upto 10^5. So the size of the array B will be very large and
	it's a waste of memory to create an array B.

Optimised Method:
    The maximum SubArray of B can be the sum of all its elements. For e.g.. if A is {3, 2, -1}
	and K is 3, then B will be {3, 2, -1, 3, 2, -1, 3, 2, -1}. The sum of all the elements in B
	will give us 12. To find this one we don't need to create the array B. We can simply find the
	sum of all the elements in array A and we can mutilply it with K. i.e (sum of elements in A)*k,
	Since B is the k-time repetition of the array A. Okay now we found out that the maximum SubArray
	of B is 12. 
    Oh Wait Wait we have just made that one wrong. Look at the array B carefully, we can omit the
	last term in it so that the sum will become 13. For this one The author uses prefix and suffix
	calculations. You can clearly understand with this example. Now array A is {-1, -2, 8, 9, 10, -2, -1}
	and consider K is 10. A is repeated 10 times in B. Consider the first repetition of A is A1, second is
	A2 and so on. So now our B array will be {A1, A2, A3, A4, A5, A6, A7, A8, A9, A10}. By finding only
	the (sum of elements in A)*k you will get the answer 270. But if you omit the first two elements in
	A1 and the last two elements in A10, You will get the Maximum SubArray as 276. So here we can check
	whether it is possible to omit some initial elements in A1 and some Final elements in A10. So the
	author is using prefix and suffix variables for that to calculate the sum of A1 and A10 specifically
	and he adds the remaining elements i.e answer = {prefix + SOE(A2) + SOE(A3) + SOE(A4) + SOE(A5) +
	SOE(A6) + SOE(A7) + SOE(A8) + SOE(A9) + suffix} , which in simplified form becomes {prefix + SOE(A)*(k-2) + suffix}. This is what he does. 
    SOE - Sum Of Elements. If SOE is positive then do this above calculation. Else just add the prefix and suffix.
    
*/
