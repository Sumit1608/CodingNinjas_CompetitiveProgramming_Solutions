#include<bits/stdc++.h>
using namespace std;

// time comp => O(digits)
// Fill all digits from rightmost to leftmost (or from least significant digit to most significant). 
// Initially deduct 1 from sum so that we have smallest digit at the end. After deducting 1, we apply
// greedy approach. We compare remaining sum with 9, if remaining sum is more than 9, we put 9 at the 
// current position, else we put the remaining sum. Since we fill digits from right to left, we put the highest digits on the right side.

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int digits, sum;
    cin >> sum >> digits ;
    // array to store the digits of the number
    int *arr = new int[digits]();
    // deduct 1 from the sum and assign it to the leftmost digit
    arr[0] = 1;
    sum--;
    
    for(int i  = digits-1; i > 0; i--){
    	// If sum is still greater than 9, digit must be 9.
        if(sum > 9){
            arr[i] = 9;
            sum = sum-9;
        } else {
            arr[i] = sum;
            sum = 0;
            break;
        }
    }
    // Whatever is left should be the most significant digit.
    // The initially subtracted 1 is incorporated here.
    arr[0] += sum;
    
    for(int i = 0; i < digits; i++)
        cout << arr[i];
    cout <<endl;
    
	return 0;
}
