#include <iostream>
using namespace std;
#include <unordered_map>

//Time comp => O(n)

//One by one insert element in the map, if there exist any 
//complement of that element, then add its frequency to the
//no of pair  bcoz  let's suppose  we have -2 and it's freq as
//3 in our map, when we insert 2,  then 3 pair of(2,-2) can be possible.

int pairSum(int *arr, int n) {
	unordered_map<int, int> freq;
    int count =0;
    
    for(int i=0; i<n; i++){
        int complement = -arr[i];
        
        if( freq.find(complement) != freq.end() ){
            count += freq[complement];
        }
        ++freq[arr[i]];
    }
    return count;
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}
