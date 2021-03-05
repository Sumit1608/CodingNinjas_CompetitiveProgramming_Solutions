#include <iostream>
using namespace std;


void rotate(int *input, int d, int n){
	//Base case
    if(n<=1){
        return;
    }
    
    //For d > n
    d = d%n;
    if(d == 0){
        return;
    }
    
    //Rotating the given array/list by D elements(towards the left) means
    // that the elements after d will become the first occuring elements of array
    // and the elements from 0th to (d-1)th elements will occur after them
    //So, we store the elements in another array and then copy them to original one
    
    // Thus  Space and Time compl => O(n)
    int arr[n];
    int j=0;
    for(int i =d; i<n; i++){
        arr[j] = input[i];
        j++;
    }
    for(int i=0; i<d; i++){
        arr[j] = input[i];
        j++;
    }
    
    for(int i=0; i<n; i++){
        input[i] = arr[i];
    }
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

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}
