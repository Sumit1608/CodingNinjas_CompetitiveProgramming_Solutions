#include <iostream>
#include <algorithm>
using namespace std;

//Time compl =>  O(n^2)

//We sort the array first,   now one by one form starting, we take an element and search for the pair
//int the right subarray for triplets.  So,  we subtarct the element from required sum k to find the pair.
//Now, when we check for pair sum in sorted array, 3 cases arise
// when the sum of starting and ending element is less than number, that means we need to go to next element 
// from starting element,   and  if it is more,  go to previous element from endElement.
// 3rd case,  if sum of starting and ending elements is equal to number,   then we check for how many such numbers
// are there.   For ex,  if num = 6,  and arr = {3,3,3,3,3,3} ,  so here,  n(n-1)/2 pairs will be there
//For ex, if n= 7 and arr = {2,2,2,4,5,5,7} ,  so here, 3*2 = 6 pairs of (2,5) will be there
//For these conditions,  we use if condition and while loop as shown in the code.

int pairSum(int *arr, int si, int ei, int num){
    int numPair =0;
    
    while(si < ei){
        if( (arr[si]+arr[ei]) < num){
            si++;
        }else if( (arr[si]+arr[ei]) > num){
            ei--;
        }
        
        else{
            int elementAtStart = arr[si];
            int elementAtEnd = arr[ei];
            //When all the elements are same
            if( elementAtStart == elementAtEnd ){
                int totalElementsFromStartToEnd = (ei-si)+1;
                numPair += ( totalElementsFromStartToEnd *(totalElementsFromStartToEnd - 1))/2;
                return numPair;
            }
            
            //When starting and ending elements are diff
            int tempsi = 0;
            int tempei = 0;
            
            //To check for how many same starting element are there, and how many same ending elements
            while(arr[si] == elementAtStart){
                si++;
                tempsi++;
            }
            while(arr[ei] == elementAtEnd){
                ei--;
                tempei++;
            }
            
            int total = tempsi*tempei ;
            numPair += total;
        }
    }
    return numPair;
}

int tripletSum(int *arr, int n, int num)
{
    sort(arr, arr+n);
    int count=0;
	for(int i=0; i<n;i++){
        int pairSumfor = num - arr[i];
        count += pairSum(arr, (i+1), (n-1), pairSumfor );
    }
    return count;
}



int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}
