#include<bits/stdc++.h>
using namespace std;

//Time Compl => O(n)
//Insert all the elements in a map and count their freq
// Then find for the element whose freq is 1 and return it

int findUnique(int *arr, int n) {
    unordered_map<int, int> m;
    
    for(int i=0;i<n; i++){
        if( m[arr[i]] == 0){
            m[arr[i]] = 1;
        } else{
            m[arr[i]]++;
        }
    }
    
    for(int i=0; i<n; i++){
        if(m[arr[i]] == 1){
            return arr[i];
        }
    }
}
int main() {
    int t;
    cin >> t;

    while (t--) {
        int size;
        cin >> size;
        int *input = new int[size];

        for (int i = 0; i < size; ++i) {
            cin >> input[i];
        }

        cout << findUnique(input, size) << endl;
    }

    return 0;
}
