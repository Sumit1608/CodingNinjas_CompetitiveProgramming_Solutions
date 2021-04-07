#include<bits/stdc++.h>
using namespace std;

/*
1. Any player can swap with the player directly at front him
2. One player can swap at most with two other players
If the specific order is formed then our team will win otherwise we will lose

Time comp => O(n)

A perfect sequence can be formed if the numbers are displaced atmost two poisiton from the initial position
if the numbers satisfies this,  then we calculate the number of swaps that will be required to make a perfect sequence
for ex =>  2 1 5 3 4 can be formed in a perfect sequence  but not 2 5 1 3 4 (5 is displaced more than 2 positions)
Now Initial state: 1 2 3 4 5
Three moves required to form this order: 1 2 3 4 5 -> 1 2 3 5 4 -> 1 2 5 3 4 -> 2 1 5 3 4
*/

int main() {
	int n;
    cin >>n;
    int arr[n];
    bool ans = true;
    for(int i=0; i<n; i++){
        cin >>arr[i];
        int var = abs(arr[i] -i);
        if(var>3){
            ans = false;
        }
    }
    
    if(!ans){
        cout <<"NO"<<endl;
    } else{
        cout <<"YES"<<endl;
        int count =0;
        for(int i=0; i<n; ){
            int var = abs(arr[i] -i);
            if(var == 3){
                count += 2;
                i += 3;
            } else if(var == 2){
                count+= 1;
                i += 2;
            } else{
                i++;
            }
        }
        cout << count <<endl;
    }
}
