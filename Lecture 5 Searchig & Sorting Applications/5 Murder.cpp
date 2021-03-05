#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

//Time comp => O(n logn)
//Example => n=5      arr = 1 5 3 6 4
//Now, we use merge sort,  and count the sum while merging the array,   let
//array is divided into two parts =>   1  5  3    &  6 4 =>   1 3 5  & 4 6 (after merging)
//  now left part willreturn 1(for 5)+1(for 3) = 2   and  right part as 0.  Now we merge the
//two parts.    We go to 1,  as one is smaller than 4, so we multiply 1 by rightArraySize( 2) 
//and add.  Then we do same for 3,   then we insert 4,  now we insert 5,  as 5 is less thna
//6, so we mulitply 5 by right arraySize(1)  ans add,  Now left array vanishes and we insert
//remaining elements and return the sum.
// Now this sum + leftSum + rightSum will be our required answer.

ll merge(int a[], int left, int mid, int right){
	int i=left, j = mid, k = 0;
	int temp[right - left +1];
	
	ll sum = 0;
	while(i<mid && j<= right){
		if(a[i] < a[j]){
            if(a[i] < a[j]){
                sum = sum + (a[i]* (right - j+1));
            }
			temp[k++] =  a[i++];
		}
		else{
			temp[k++] = a[j++];
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
	return sum ;
}

ll merge_sort(int a[], int left, int right){
	if(right > left){
		int mid = (right+left)/2;
		ll sumLeft = merge_sort(a, left, mid);
		ll sumRight = merge_sort(a, mid+1, right);
		ll sumMerge = merge(a, left, mid+1, right);
		return (sumLeft + sumRight + sumMerge);
	}
	return 0;
}

ll solve(int a[], int n){
	ll ans = merge_sort(a, 0, n-1);
	return ans;
}

int main(){
    int t;
    cin>>t;
    while(t--){
		int n;
		cin >> n;
		int arr[n];
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}
	
		cout << solve(arr, n) << endl;

    }
}

