#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	long prod[n];
	for(int i =0; i <n ; i++){
		cin>>arr[i];
	}
	
	//lp = leftproduct          rp = rightproduct
	// Create the prefix product and at the same time store it in the product array P
	long lp = 1;
	for(int i =0; i<n; i++){
		prod[i] = lp;
		lp = lp*arr[i];
	}
	
	// Create the suffix product and Multiply the
	//current suffix value with the value at p[i] to get the required answer
	long rp = 1;
	for(int i = n-1; i >=0; i--){
		prod[i] *= rp;
		rp *= arr[i];
	}
	
	for(int i=0; i<n; i++){
		cout << prod[i] << " ";
	}
	cout<<endl;
}


/*
Optimal Approach with 2 extra array
Create an array ‘P’ of size N.
If n = 1 then initialize P[0]=0 and return.
Create two array prefix and suffix.
Prefix array stores product till i’th position excluding i’th element from the left side.
Suffix array stores product till i’th position excluding i’th element from the right side.
Initialize Prefix[0] = 1 and start loop from i = 1 to i = N - 1
Prefix[i] = Prefix[i-1] * ARR[i-1]
The prefix[i] will store the product of all the elements till i-1 index from the left side.
Initialize Suffix[N-1] = 1 and start loop from i = N-2 to i = 0
Suffix[i] = Suffix[i+1] * ARR[i+1]
The Suffix[i] will store the product of all the elements till i+1 index from the right side.
Now run a loop from i = 0 to i = N - 1
P[i] = Prefix[i] * Suffix[i]
Now P[i] has the product of all the elements except the i’th element.
Now P has the required answer, therefore, return the P array.
Time Complexity
O(N), where N is the number of elements in the array.

Creating Prefix, Suffix and P array requires only one traversal for each array.

Space Complexity
O(N), We are using three arrays of size N.




This will be the best solution 

Optimal Approach
Create an array ‘P’ of size N.
If n = 1 then initialize P[0]=0 and return.
Initialize the P array with 1.
Initialize a variable temp = 1 which will be used in place of the prefix array and run a loop from i = 0 to i = N - 1 and Initialize
P[i] = temp
temp *= ARR[i]
Again re-initialize temp = 1 now this will be used in place of suffix array and at the same time, we will multiply it with P[i] which has the
prefix value to get the required answer.
Run a loop from i = N - 1 to i = 0 and
P[i] *= temp
temp[i] *= ARR[i]
Now P array has the required answer, therefore, return the P array.
Time Complexity
O(N), where N is the number of elements in the array.

All the operations require only one traversal.

Space Complexity
O(1), We are using constant extra space.


*/
