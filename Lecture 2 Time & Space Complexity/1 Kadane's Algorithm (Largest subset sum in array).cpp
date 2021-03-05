#include <iostream>
using namespace std;

int kadane ( int *arr, int n){
	int current_sum = 0;
	int best_sum = 0;
	
	for(int i =0; i<n; i++){
		current_sum += arr[i];
		if(best_sum < current_sum){
			best_sum = current_sum;
		}
		if(current_sum<0){
			current_sum = 0;
		}
	}
	
	return best_sum;
}

int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i =0; i <n ; i++){
		cin>>arr[i];
	}
	
	cout << kadane(arr, n) <<endl;
}


/*

Explanation:
Simple idea of the Kadane’s algorithm is to look for all positive contiguous
segments of the array (max_ending_here is used for this). And keep track of
maximum sum contiguous segment among all positive segments (max_so_far is used
for this). Each time we get a positive sum compare it with max_so_far and update
max_so_far if it is greater than max_so_far.

    Lets take the example:
    Input ===> {-2, -3, 4, -1, -2, 1, 5, -3}
    Output ===> 7

    max_so_far = max_ending_here = 0

    for i=0,  a[0] =  -2
    max_ending_here = max_ending_here + (-2)
    Set max_ending_here = 0 because max_ending_here < 0

    for i=1,  a[1] =  -3
    max_ending_here = max_ending_here + (-3)
    Set max_ending_here = 0 because max_ending_here < 0

    for i=2,  a[2] =  4
    max_ending_here = max_ending_here + (4)
    max_ending_here = 4
    max_so_far is updated to 4 because max_ending_here greater 
    than max_so_far which was 0 till now

    for i=3,  a[3] =  -1
    max_ending_here = max_ending_here + (-1)
    max_ending_here = 3

    for i=4,  a[4] =  -2
    max_ending_here = max_ending_here + (-2)
    max_ending_here = 1

    for i=5,  a[5] =  1
    max_ending_here = max_ending_here + (1)
    max_ending_here = 2

    for i=6,  a[6] =  5
    max_ending_here = max_ending_here + (5)
    max_ending_here = 7
    max_so_far is updated to 7 because max_ending_here is 
    greater than max_so_far

    for i=7,  a[7] =  -3
    max_ending_here = max_ending_here + (-3)
    max_ending_here = 4
    
*/
