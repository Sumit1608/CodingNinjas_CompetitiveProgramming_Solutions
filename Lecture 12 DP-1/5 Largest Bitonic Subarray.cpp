#include<iostream>
using namespace std;

// Time comp => O(n^2),   same as the longest increasing subsequence
// To find the largest bitonic series,  find lis and lds from left to right and right to left respectively
// Now,  either the whole series can be increasing, decreasing or half increasing and half decreasing
// Find out using a loop,  make sure that the increasing series end and decreasing series start shouldn't be same.
//Ex =>  arr =  15 20 20 6 4 2
//inc[] =  1  2  2  1 1 1
//dec[] =  4  4  4  3 2 1
// we get ans as 4 +2 => 6
int longestBitonicSubarray(int *input, int n){
    int inc[n];
	inc[0] = 1;
	for(int i=1; i<n; i++){
		inc[i] = 1;
		for(int j=i-1; j>=0; j--){
			if(input[j] >= input[i]){
				continue;
			}
            int possibleAns = inc[j] +1;
			if(possibleAns > inc[i]){
				inc[i] = possibleAns;
			}
		}
	}
    
    int dec[n];
	dec[n-1] = 1;
	for(int i=n-2; i>= 0; i--){
		dec[i] = 1;
		for(int j=n-1; j>i; j--){
			if(input[j] >= input[i]){
				continue;
			}
            int possibleAns = dec[j] +1;
			if(possibleAns > dec[i]){
				dec[i] = possibleAns;
			}
		}
	}
    
    int ans = dec[0];
    for(int i=0; i<n; i++){
        int j= i+1;
        while(j <n){
            if(input[i] != input[j] ){
                ans = max(ans, inc[i]+dec[j]);
            }
            j++;
        }
    }
    
    return ans;
    
}
int main() {
	int n, input[100000];
  	cin>>n;
  	for(int i=0; i<n; i++) {
    	cin>>input[i];
  	}
  	cout<<longestBitonicSubarray(input, n);
  	return 0;
}
