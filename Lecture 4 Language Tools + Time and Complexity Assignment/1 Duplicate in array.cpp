#include <bits/stdc++.h>
using namespace std;

// As the number are present from 0 to (n-2) only,  so first find out the total
// sum of the numbers from 0 to n-2. Now, subtract each number form the array 
// from the totalsum, and return the absoulte of the totalsum.
// That means (sumofElements - sumOfNminusTwoNumbers) will be ans.

//For example n=5, then from 0 to 3 numbers will be there in array, and
// total sum = 0+1+2+3=6. If we subtract numbers from array then we will left
// with the negative of duplicate term only.
int findDuplicate(int *arr, int n)
{
    int total = ((n-1)*(n-2))/2;
    for(int i=0; i<n; i++){
        total -= arr[i];
    }
    return abs(total);
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		cout << findDuplicate(input, size) << endl;
	}

	return 0;
}
