#include <iostream>
using namespace std;

// recursive approach
int coin_change(int n, int* d, int numD) {
	if (n == 0) {
		return 1;
	}
	if (n < 0) {
		return 0;
	}
	if (numD == 0) {
		return 0;
	}
	
	// The coin change can either have the ith coin or not
	int first = coin_change(n - d[0], d, numD);
	int second = coin_change(n, d + 1, numD - 1);
	return first + second;
}

int main() {
	int d[3] = {1,2,3};
	cout << coin_change(8, d, 3) << endl;
}

