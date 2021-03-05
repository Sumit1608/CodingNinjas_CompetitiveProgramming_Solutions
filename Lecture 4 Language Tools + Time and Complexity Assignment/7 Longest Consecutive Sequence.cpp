#include <bits/stdc++.h>
using namespace std;

//Time comp => O(n)

// Algorithm: 
//Create an empty hash.
//Insert all array elements to hash.
//Do following for every element arr[i]
//Check if this element is the starting point of a subsequence. To check this, simply
//look for arr[i] – 1 in the hash, if not found, then this is the first element a subsequence.
//If this element is the first element, then count the number of elements in the consecutive
//starting with this element. Iterate from arr[i] + 1 till the last element that can be found.
//If the count is more than the previous longest subsequence found, then update this.


vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    unordered_map<int, bool> freq;
    unordered_map<int, int> index;
    for(int i=0; i<n; i++){
        freq[arr[i]] = true;
        index[arr[i]] = i;
    }
    int max_length = 1;
    int startingElement = arr[0];
    int startingElementIndex = 0;
    int endingElement = INT_MIN;
    
    for(int i=0; i<n; i++){
        if(freq[arr[i]]){
            int smallMax = 1;
            int numBig = arr[i]+1;
            int numSmall = arr[i]-1;
            
            while(freq[numBig]){
                smallMax++;
                freq[numBig] = false;
                numBig++;
            }
            while(freq[numSmall]){
                smallMax++;
                freq[numSmall] = false;
                numSmall--;
            }
            
            if(max_length < smallMax){
                max_length = smallMax;
                startingElement = numSmall+1;
                startingElementIndex = index[startingElement];
                endingElement = numBig - 1;
            }
            else if( max_length == smallMax){
                if(index[numSmall+1] < startingElementIndex){
                    startingElement = numSmall+1;
                    startingElementIndex = index[startingElement];
                	endingElement = numBig - 1;
                }
            }
        }
    }
    
    vector<int> v;
    v.push_back(startingElement);
    if(endingElement != INT_MIN)
    	v.push_back(endingElement);
    
    return v;
}


int main() {
    int size;
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    cout << ans[0];
    if (ans.size() > 1) {
        cout << " " << ans[ans.size() - 1];
    }

    delete[] arr;
}
