#include<bits/stdc++.h>
using namespace std;

// time comp => O(nlogn)
// sort all the elements, now to minimize the difference, we subtract k from last element
// and add k to the starting element. Now, don't perform any operation on the elements,
// just store the max and min value
// Now, for all elements check if subtract(element-k) and add(element+k) makes any changes or not.
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,k;
    cin >> n >> k;
    
	int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >>arr[i];
    }
    sort(arr, arr+n);
    //initialize ans
    int ans = arr[n-1] - arr[0];
    // max and min numbers
    int maxNo = arr[n-1] -k;
    int minNo = arr[0] + k;
    if(maxNo < minNo){
        int temp = maxNo;
        maxNo = minNo;
        minNo = temp;
    }
    
    for(int i = 1; i < n-1; i++){
        int add = arr[i] + k;
        int subtract = arr[i] - k;
        // If both subtraction and addition do not change diff
        if(subtract >= minNo || add <= maxNo)
            continue;
        // Either subtraction causes a smaller number or addition causes a greater
        // number. Update small or big using greedy approach (If big - subtract
        // causes smaller diff, update small Else update big)
        if((maxNo - subtract) <= (add - minNo) )
            minNo = subtract;
        else
            maxNo = add;
        
    }
    ans = min(ans, maxNo - minNo);
    cout << ans <<endl;
    return 0;
}



